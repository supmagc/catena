#include "Rock_Std.h"
#include "Rock_Matrix4x4.h"

using namespace Rock;

Matrix4x4::Matrix4x4() {
    ZeroMemory(&v, 16 * RFLOAT_SIZE);
}

Matrix4x4::~Matrix4x4() {
}

Matrix4x4::Matrix4x4(Matrix4x4 const& mCopy) {
    if(this == &mCopy)
        return;

    memcpy_s(v, 16 * RFLOAT_SIZE, mCopy.v, 16 * RFLOAT_SIZE);
}

Matrix4x4& Matrix4x4::operator=(Matrix4x4 const& mCopy) {
    if(this != &mCopy)
        memcpy_s(v, 16 * RFLOAT_SIZE, mCopy.v, 16 * RFLOAT_SIZE);
    
    return *this;
}

void Matrix4x4::SetRow(RINT const nRow, Vector4 const& vRow) {
    rc[nRow][0] = vRow.x;
    rc[nRow][1] = vRow.y;
    rc[nRow][2] = vRow.z;
    rc[nRow][3] = vRow.w;
}

void Matrix4x4::SetRow(RINT const nRow, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3) {
    rc[nRow][0] = n0;
    rc[nRow][1] = n1;
    rc[nRow][2] = n2;
    rc[nRow][3] = n3;
}

void Matrix4x4::SetColumn(RINT const nColumn, Vector4 const& vColumn) {
    rc[0][nColumn] = vColumn.x;
    rc[1][nColumn] = vColumn.y;
    rc[2][nColumn] = vColumn.z;
    rc[3][nColumn] = vColumn.w;
}

void Matrix4x4::SetColumn(RINT const nColumn, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3) {
    rc[0][nColumn] = n0;
    rc[1][nColumn] = n1;
    rc[2][nColumn] = n2;
    rc[3][nColumn] = n3;
}

void Matrix4x4::SetAxisX(Vector3 const& vAxis) {
    _11 = vAxis.x;
    _12 = vAxis.y;
    _13 = vAxis.z;
}

void Matrix4x4::SetAxisX(RFLOAT x, RFLOAT y, RFLOAT z) {
    _11 = x;
    _12 = y;
    _13 = z;
}

void Matrix4x4::SetAxisY(Vector3 const& vAxis) {
    _21 = vAxis.x;
    _22 = vAxis.y;
    _23 = vAxis.z;
}

void Matrix4x4::SetAxisY(RFLOAT x, RFLOAT y, RFLOAT z) {
    _21 = x;
    _22 = y;
    _23 = z;
}

void Matrix4x4::SetAxisZ(Vector3 const& vAxis) {
    _31 = vAxis.x;
    _32 = vAxis.y;
    _33 = vAxis.z;
}

void Matrix4x4::SetAxisZ(RFLOAT x, RFLOAT y, RFLOAT z) {
    _31 = x;
    _32 = y;
    _33 = z;
}

void Matrix4x4::SetPosition(Vector3 const& vPosition) {
    _41 = vPosition.x;
    _42 = vPosition.y;
    _43 = vPosition.z;
}

void Matrix4x4::SetPosition(RFLOAT x, RFLOAT y, RFLOAT z) {
    _41 = x;
    _42 = y;
    _43 = z;
}

void Matrix4x4::SetCell(RINT nRow, RINT nColumn, RFLOAT nCell) {
    rc[nRow][nColumn] = nCell;
}

void Matrix4x4::GetRow(RINT nRow, Vector4& o_vRow) const {
    o_vRow.x = rc[nRow][0];
    o_vRow.y = rc[nRow][1];
    o_vRow.z = rc[nRow][2];
    o_vRow.w = rc[nRow][3];
}

Vector4 Matrix4x4::GetRow(RINT nRow) const {
    return Vector4(rc[nRow][0], rc[nRow][1], rc[nRow][2], rc[nRow][3]);
}

void Matrix4x4::GetColumn(RINT nColumn, Vector4& o_vColumn) const {
    o_vColumn.x = rc[0][nColumn];
    o_vColumn.y = rc[1][nColumn];
    o_vColumn.z = rc[2][nColumn];
    o_vColumn.w = rc[3][nColumn];
}

Vector4 Matrix4x4::GetColumn(RINT nColumn) const {
    return Vector4(rc[0][nColumn], rc[1][nColumn], rc[2][nColumn], rc[3][nColumn]);
}

void Matrix4x4::GetAxisX(Vector3& o_vAxis) const {
    o_vAxis.x = _11;
    o_vAxis.y = _12;
    o_vAxis.z = _13;
}

Vector3 Matrix4x4::GetAxisX() const {
    return Vector3(_11, _12, _13);
}

void Matrix4x4::GetAxisY(Vector3& o_vAxis) const {
    o_vAxis.x = _21;
    o_vAxis.y = _22;
    o_vAxis.z = _23;
}

Vector3 Matrix4x4::GetAxisY() const {
    return Vector3(_21, _22, _23);
}

void Matrix4x4::GetAxisZ(Vector3& o_vAxis) const {
    o_vAxis.x = _31;
    o_vAxis.y = _32;
    o_vAxis.z = _33;
}

Vector3 Matrix4x4::GetAxisZ() const {
    return Vector3(_31, _32, _33);
}

void Matrix4x4::GetPosition(Vector3& o_vPosition) const {
    o_vPosition.x = _41;
    o_vPosition.y = _42;
    o_vPosition.z = _43;
}

Vector3 Matrix4x4::GetPosition() const {
    return Vector3(_41, _42, _43);
}

void Matrix4x4::GetCell(RINT nRow, RINT nColumn, RFLOAT& o_nValue) const {
    o_nValue = rc[nRow][nColumn];
}

RFLOAT Matrix4x4::GetCell(RINT nRow, RINT nColumn) const {
    return rc[nRow][nColumn];
}

void Matrix4x4::MakeIdentity() {
    ZeroMemory(v, sizeof(v));
    _11 = 1;
    _22 = 1;
    _33 = 1;
    _44 = 1;
}

void Matrix4x4::MakeInverse() {

}

Matrix4x4 Matrix4x4::CreatePerspectiveLH(RFLOAT nFOV, RFLOAT nAspectRatio, RFLOAT nNearClipping, RFLOAT nFarClipping) {
    Matrix4x4 m = Matrix4x4();
    RFLOAT nF = static_cast<RFLOAT>(1/(tan(nFOV/2)));
    m._11 = nF/nAspectRatio;
    m._21 = nF;
    m._33 = nFarClipping / (nFarClipping - nNearClipping);
    m._34 = 1;
    m._43 = (-nNearClipping * nFarClipping) / (nFarClipping - nNearClipping);
    return m;
}

Matrix4x4 Matrix4x4::CreatePerspectiveRH(RFLOAT nFOV, RFLOAT nAspectRatio, RFLOAT nNearClipping, RFLOAT nFarClipping) {
    Matrix4x4 m = Matrix4x4();
    RFLOAT nF = static_cast<RFLOAT>(1/(tan(nFOV/2)));
    m._11 = nF/nAspectRatio;
    m._21 = nF;
    m._33 = nFarClipping / (nFarClipping - nNearClipping);
    m._34 = -1;
    m._43 = (-nNearClipping * nFarClipping) / (nFarClipping - nNearClipping);
    return m;
}

Matrix4x4 Matrix4x4::CreateIdentity() {
    Matrix4x4 m = Matrix4x4();
    m.MakeIdentity();
    return m;
}

Matrix4x4 Matrix4x4::CreateViewLH(Vector3 const& vPosition, Vector3 const& vLookat, Vector3 const& vUp) {
    //Vector3 vZ = vLookat - vPosition; vZ.Normalize();
    //Vector3 vX, vY;
    //CrossLH(vZ, vUp, vX); vX.Normalize();
    //CrossRH(vZ, vX, vY); vY.Normalize();
    Matrix4x4 m = Matrix4x4();
    //M.m[0]  = vX.x;
    //M.m[4]  = vX.y;
    //M.m[8]  = vX.z;
    //Dot(vX, vPosition, M.m[12]); M.m[12] *= -1;
    //M.m[1]  = vY.x;
    //M.m[5]  = vY.y;
    //M.m[9]  = vY.z;
    //Dot(vY, vPosition, M.m[13]); M.m[13] *= -1;
    //M.m[2]  = vZ.x;
    //M.m[6]  = vZ.y;
    //M.m[10] = vZ.z;
    //Dot(vZ, vPosition, M.m[14]); M.m[14] *= -1;
    return m;
}

Matrix4x4 Matrix4x4::CreateViewRH(Vector3 const& vPosition, Vector3 const& vLookat, Vector3 const& vUp) {
    //Vector3 vZ = vLookat - vPosition; vZ.Normalize();
    //Vector3 vX, vY;
    //CrossLH(vZ, vUp, vX); vX.Normalize();
    //CrossRH(vZ, vX, vY); vY.Normalize();
    Matrix4x4 m = Matrix4x4();
    //M.m[0]  = vX.x;
    //M.m[4]  = vX.y;
    //M.m[8]  = vX.z;
    //M.m[12] = -vPosition.x;//Dot(vPosition, vX);
    //M.m[1]  = vY.x;
    //M.m[5]  = vY.y;
    //M.m[9]  = vY.z;
    //M.m[13] = -vPosition.y;//Dot(vPosition, vY);
    //M.m[2]  = vZ.x;
    //M.m[6]  = vZ.y;
    //M.m[10] = vZ.z;
    //M.m[14] = -vPosition.z;//Dot(vPosition, vZ);
    return m;
}

Matrix4x4 Matrix4x4::CreateScale(Vector3 const& vIn) {
    Matrix4x4 m = Matrix4x4();
    return m;
}

Matrix4x4 Matrix4x4::CreateTranslate(Vector3 const& vIn) {
    Matrix4x4 m = Matrix4x4();
    return m;
}

Matrix4x4 Matrix4x4::CreateRotateX(RFLOAT nRot) {
    Matrix4x4 m = Matrix4x4();
    return m;
}

Matrix4x4 Matrix4x4::CreateRotateY(RFLOAT nRot) {
    Matrix4x4 m = Matrix4x4();
    return m;
}

Matrix4x4 Matrix4x4::CreateRotateZ(RFLOAT nRot) {
    Matrix4x4 m = Matrix4x4();
    return m;
}
