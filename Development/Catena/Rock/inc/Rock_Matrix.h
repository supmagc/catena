#ifndef _H_ROCK_MATRIX
#define _H_ROCK_MATRIX 1

#include "Rock_Vector.h"
#include "Rock_Types.h"
#include "Rock_Checks.h"

namespace Rock {

    template<typename TMat, RUINT TMatRows, RUINT TMatColumns, typename CRTP>
    struct MatrixBase {
        INLINE CRTP& Crtp() { return static_cast<CRTP&>(*this); }
        INLINE CRTP const& Crtp() const { return static_cast<CRTP const&>(*this); }

        MatrixBase() { catMemZero(this, sizeof(TMat) * TMatRows * TMatColumns); }

        Vector<TMat, TMatColumns>& operator[](RUINT const i) {
            CHECK_SLOW_TRUE(i < TMatRows);
            CHECK_SLOW_TRUE(i >= 0);
            return Rctp().rows[i];
        }

        Vector<TMat, TMatColumns> const& operator[](RUINT const i) const {
            CHECK_SLOW_TRUE(i < TMatRows);
            CHECK_SLOW_TRUE(i >= 0);
            return Rctp().rows[i];
        }
    };

    template<typename TMat, RUINT TMatRows, RUINT TMatColumns>
    struct Matrix : MatrixBase<TMat, TMatRows, TMatColumns, Matrix<TMat, TMatRows, TMatColumns>> {
        union {
            TMat data[TMatRows][TMatColumns];
            Vector<TMat, TMatColumns> rows[TMatRows];
        };
    };

    template<typename TMat>
    struct Matrix<TMat, 3, 3> : MatrixBase<TMat, 3, 3, Matrix<TMat, 3, 3>>{
        union {
            TMat data[3][3];
            Vector<TMat, 3> rows[3];
            struct { Vector3 r0, r1, r2; };
            struct { TMat c00, c01, c02, c10, c11, c12, c20, c21, c22; };
        };
    };

    template<typename TMat>
    struct Matrix<TMat, 4, 4> : MatrixBase<TMat, 4, 4, Matrix<TMat, 4, 4>>{
        union{
            TMat data[4][4];
            Vector<TMat, 4> rows[4];
            struct { Vector4 r0, r1, r2, r3; };
            struct { TMat c00, c01, c02, c03, c10, c11, c12, c13, c20, c21, c22, c23, c30, c31, c32, c33; };
            struct { Vector3 r0; TMat c03; Vector3 r1; TMat c13; Vector3 r2; TMat c23; Vector3 r3; TMat c33; };
        };
    };

    typedef Matrix<RFLOAT, 4, 4> Matrix44;
    typedef Matrix<RFLOAT, 3, 3> Matrix33;
    typedef Matrix44 RMatrix44;
    typedef Matrix33 RMatrix33;
};

#endif // _H_ROCK_MATRIX