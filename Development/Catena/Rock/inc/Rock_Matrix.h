#ifndef _H_ROCK_MATRIX
#define _H_ROCK_MATRIX 1

#include "Rock_Vector.h"
#include "Rock_Types.h"

namespace Rock {

    template<typename TMat, RUINT TMatRows, RUINT TMatColumns>
    struct Matrix {
        TMat data[TMatRows][TMaxColumns];

        Matrix() { catMemZero(this, sizeof(TMat) * TMatRows * TMatColumns); }
    };

    template<typename TMat>
    struct Matrix<TMat, 4, 4> {
        union{
            TMat data[4][4];
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