#include "Rock_Std.h"
#include "Rock_Matrix.h"

using namespace Rock;

Matrix33 m33A = Matrix33();
Matrix33 m33B = Matrix33();
Matrix44 m44A = Matrix44();
Matrix44 m44B = Matrix44();

struct A {
    A(int, int) {}
};

struct B : A {
    B(int) : A(0, 0) {}
    using A::A;
};

void Main() {
    B* b = new B(0, 1);

    m44A[2][1] = m44B[0][2];
    m44B = Matrix44(Vector3(), Vector3(), Vector3(), Vector3(), 2);

    auto tmp0 = Matrix<RFLOAT, 2, 6>::Identity();
    auto tmp1 = Matrix<RFLOAT, 6, 6>::Identity();
    auto tmp2 = Matrix<RFLOAT, 6, 2>::Identity();

    //auto tmp = MakeIdentity<RFLOAT>(5, 5);
}