#include "Rock_Std.h"
#include "Rock_Matrix4x4.h"
#include "Rock_Defines.h"
#include "Rock_Functions.h"

using namespace Rock;

Matrix4x4::Matrix4x4() {
    catMemZero(&v, sizeof(Matrix4x4));
    _11 = 1;
    _22 = 1;
    _33 = 1;
    _44 = 1;
}

Matrix4x4::~Matrix4x4() {
}

Matrix4x4::Matrix4x4(Matrix4x4 const& mCopy) {
    if(this == &mCopy)
        return;

    memcpy_s(v, 16 * RFLOAT_SIZE, mCopy.v, 16 * RFLOAT_SIZE);
}
