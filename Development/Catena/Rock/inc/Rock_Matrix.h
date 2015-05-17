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

        typedef TMat Type;
        MatrixBase() { catMemZero(this, sizeof(TMat) * TMatRows * TMatColumns); }

        INLINE Vector<TMat, TMatColumns>& operator[](RUINT const i) {
            CHECK_SLOW_TRUE(i < TMatRows);
            CHECK_SLOW_TRUE(i >= 0);
            return Crtp().rows[i];
        }

        INLINE Vector<TMat, TMatColumns> const& operator[](RUINT const i) const {
            CHECK_SLOW_TRUE(i < TMatRows);
            CHECK_SLOW_TRUE(i >= 0);
            return Crtp().rows[i];
        }
    };

    template<typename TMat, RUINT TMatRows, RUINT TMatColumns>
    struct ROCK_API Matrix : MatrixBase<TMat, TMatRows, TMatColumns, Matrix<TMat, TMatRows, TMatColumns>> {
        union {
            TMat data[TMatRows][TMatColumns];
            Vector<TMat, TMatColumns> rows[TMatRows];
        };
    };

    template<typename TMat>
    struct ROCK_API Matrix<TMat, 3, 3> : MatrixBase<TMat, 3, 3, Matrix<TMat, 3, 3>>{
        union {
            TMat data[3][3];
            Vector<TMat, 3> rows[3];
            struct { Vector3 r0, r1, r2; };
            struct { Vector3 x, y, z; };
            struct { TMat c00, c01, c02, c10, c11, c12, c20, c21, c22; };
        };

        Matrix() : Matrix(0) {}
        explicit Matrix(TMat const& n) : Matrix(n, 0, 0, 0, n, 0, 0, 0, n) {}
        Matrix(TMat const& n00, TMat const& n01, TMat const& n02, 
               TMat const& n10, TMat const& n11, TMat const& n12, 
               TMat const& n20, TMat const& n21, TMat const& n22) : 
               c00(n00), c01(n01), c02(n02), 
               c10(n10), c11(n11), c12(n12), 
               c20(n20), c21(n21), c22(n22) {}
    };

    template<typename TMat>
    struct ROCK_API Matrix<TMat, 4, 4> : MatrixBase<TMat, 4, 4, Matrix<TMat, 4, 4>>{
        union{
            TMat data[4][4];
            Vector<TMat, 4> rows[4];
            struct { Vector4 r0, r1, r2, r3; };
            struct { TMat c00, c01, c02, c03, c10, c11, c12, c13, c20, c21, c22, c23, c30, c31, c32, c33; };
            struct { Vector3 x; TMat cX3; Vector3 y; TMat cY3; Vector3 z; TMat cZ3; Vector3 pos; TMat scale; };
        };

        Matrix() : Matrix(0) {}
        explicit Matrix(TMat const& n) : Matrix(n, 0, 0, 0, 0, n, 0, 0, 0, 0, n, 0, 0, 0, 0, n) {}
        Matrix(TMat const& n00, TMat const& n01, TMat const& n02, TMat const& n03,
               TMat const& n10, TMat const& n11, TMat const& n12, TMat const& n13,
               TMat const& n20, TMat const& n21, TMat const& n22, TMat const& n23,
               TMat const& n30, TMat const& n31, TMat const& n32, TMat const& n33) :
               c00(n00), c01(n01), c02(n02), c03(n03),
               c10(n10), c11(n11), c12(n12), c13(n13),
               c20(n20), c21(n21), c22(n22), c23(n23),
               c30(n20), c31(n21), c32(n22), c33(n33) {}
    };

    typedef Matrix<RFLOAT, 4, 4> Matrix44;
    typedef Matrix<RFLOAT, 3, 3> Matrix33;
    typedef Matrix44 RMatrix44;
    typedef Matrix33 RMatrix33;
};

#endif // _H_ROCK_MATRIX