#include "Rock_Std.h"
#include "Rock_Matrix4x4.h"

using namespace Rock;

Matrix4x4::Matrix4x4() {
    ZeroMemory(&m, 16 * RFLOAT_SIZE);
}

Matrix4x4::~Matrix4x4() {
}

Matrix4x4::Matrix4x4(Matrix4x4 const& mCopy) {
    if(this == &mCopy)
        return;

    memcpy_s(m, 16 * RFLOAT_SIZE, mCopy.m, 16 * RFLOAT_SIZE);
}

Matrix4x4& Matrix4x4::operator=(Matrix4x4 const& mCopy) {
    if(this != &mCopy)
        memcpy_s(m, 16 * RFLOAT_SIZE, mCopy.m, 16 * RFLOAT_SIZE);
    
    return *this;
}

void Matrix4x4::SetRow(RINT const nRow, Vector4 const& vRow) {
    m[4*nRow+0] = vRow.x;
    m[4*nRow+1] = vRow.y;
    m[4*nRow+2] = vRow.z;
    m[4*nRow+3] = vRow.w;
}

void Matrix4x4::SetRow(RINT const nRow, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3) {
    m[4*nRow+0] = n0;
    m[4*nRow+1] = n1;
    m[4*nRow+2] = n2;
    m[4*nRow+3] = n3;
}

void Matrix4x4::SetColumn(RINT const nColumn, Vector4 const& vColumn) {
    m[ 0+nColumn] = vColumn.x;
    m[ 4+nColumn] = vColumn.y;
    m[ 8+nColumn] = vColumn.z;
    m[12+nColumn] = vColumn.w;
}

void Matrix4x4::SetColumn(RINT const nColumn, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3) {
    m[ 0+nColumn] = n0;
    m[ 4+nColumn] = n1;
    m[ 8+nColumn] = n2;
    m[12+nColumn] = n3;
}

void Matrix4x4::SetAxisX(Vector3 const& vAxis) {

}

void Matrix4x4::SetAxisX(RFLOAT n0, RFLOAT n1, RFLOAT n2) {

}

void Matrix4x4::SetAxisY(Vector3 const& vAxis) {

}

void Matrix4x4::SetAxisY(RFLOAT n0, RFLOAT n1, RFLOAT n2) {

}

void Matrix4x4::SetAxisZ(Vector3 const& vAxis) {

}

void Matrix4x4::SetAxisZ(RFLOAT n0, RFLOAT n1, RFLOAT n2) {

}

void Matrix4x4::SetPosition(Vector3 const& vValue) {

}

void Matrix4x4::SetPosition(RFLOAT n0, RFLOAT n1, RFLOAT n2) {

}

void Matrix4x4::SetCell(RINT nRow, RINT nColumn, RFLOAT nCell) {

}

