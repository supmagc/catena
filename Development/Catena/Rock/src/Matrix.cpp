#include "Rock_Std.h"
#include "Rock_Matrix.h"

using namespace Rock;

Matrix33 m33A = Matrix33();
Matrix33 m33B = Matrix33();
Matrix44 m44A = Matrix44();
Matrix44 m44B = Matrix44();

void Main() {
    m44A[2][1] = m44B[0][2];
    m44B = Matrix44(Vector3(), Vector3(), Vector3(), Vector3(), 2);

    //auto tmp = MakeIdentity<RFLOAT>(5, 5);
}