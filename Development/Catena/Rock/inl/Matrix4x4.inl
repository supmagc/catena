inline void Matrix4x4::SetRow(RINT const nRow, Vector4 const& vRow) {
    rc[nRow][0] = vRow.x;
    rc[nRow][1] = vRow.y;
    rc[nRow][2] = vRow.z;
    rc[nRow][3] = vRow.w;
}

inline void Matrix4x4::SetRow(RINT const nRow, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3) {
    rc[nRow][0] = n0;
    rc[nRow][1] = n1;
    rc[nRow][2] = n2;
    rc[nRow][3] = n3;
}

inline void Matrix4x4::SetColumn(RINT const nColumn, Vector4 const& vColumn) {
    rc[0][nColumn] = vColumn.x;
    rc[1][nColumn] = vColumn.y;
    rc[2][nColumn] = vColumn.z;
    rc[3][nColumn] = vColumn.w;
}

inline void Matrix4x4::SetColumn(RINT const nColumn, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3) {
    rc[0][nColumn] = n0;
    rc[1][nColumn] = n1;
    rc[2][nColumn] = n2;
    rc[3][nColumn] = n3;
}

inline void Matrix4x4::SetAxisX(Vector3 const& vAxis) {
    _11 = vAxis.x;
    _12 = vAxis.y;
    _13 = vAxis.z;
}

inline void Matrix4x4::SetAxisX(RFLOAT x, RFLOAT y, RFLOAT z) {
    _11 = x;
    _12 = y;
    _13 = z;
}

inline void Matrix4x4::SetAxisY(Vector3 const& vAxis) {
    _21 = vAxis.x;
    _22 = vAxis.y;
    _23 = vAxis.z;
}

inline void Matrix4x4::SetAxisY(RFLOAT x, RFLOAT y, RFLOAT z) {
    _21 = x;
    _22 = y;
    _23 = z;
}

inline void Matrix4x4::SetAxisZ(Vector3 const& vAxis) {
    _31 = vAxis.x;
    _32 = vAxis.y;
    _33 = vAxis.z;
}

inline void Matrix4x4::SetAxisZ(RFLOAT x, RFLOAT y, RFLOAT z) {
    _31 = x;
    _32 = y;
    _33 = z;
}

inline void Matrix4x4::SetPosition(Vector3 const& vPosition) {
    _41 = vPosition.x;
    _42 = vPosition.y;
    _43 = vPosition.z;
}

inline void Matrix4x4::SetPosition(RFLOAT x, RFLOAT y, RFLOAT z) {
    _41 = x;
    _42 = y;
    _43 = z;
}

inline void Matrix4x4::SetCell(RINT nRow, RINT nColumn, RFLOAT nCell) {
    rc[nRow][nColumn] = nCell;
}

inline Vector4 Matrix4x4::GetRow(RINT nRow) const {
    return Vector4(rc[nRow][0], rc[nRow][1], rc[nRow][2], rc[nRow][3]);
}

inline Vector4 Matrix4x4::GetColumn(RINT nColumn) const {
    return Vector4(rc[0][nColumn], rc[1][nColumn], rc[2][nColumn], rc[3][nColumn]);
}

inline Vector3 Matrix4x4::GetAxisX() const {
    return Vector3(_11, _12, _13);
}

inline Vector3 Matrix4x4::GetAxisY() const {
    return Vector3(_21, _22, _23);
}

inline Vector3 Matrix4x4::GetAxisZ() const {
    return Vector3(_31, _32, _33);
}

inline Vector3 Matrix4x4::GetPosition() const {
    return Vector3(_41, _42, _43);
}

inline RFLOAT Matrix4x4::GetCell(RINT nRow, RINT nColumn) const {
    return rc[nRow][nColumn];
}

inline void Matrix4x4::GetRow(RINT nRow, Vector4& o_vRow) const {
    o_vRow.x = rc[nRow][0];
    o_vRow.y = rc[nRow][1];
    o_vRow.z = rc[nRow][2];
    o_vRow.w = rc[nRow][3];
}

inline void Matrix4x4::GetColumn(RINT nColumn, Vector4& o_vColumn) const {
    o_vColumn.x = rc[0][nColumn];
    o_vColumn.y = rc[1][nColumn];
    o_vColumn.z = rc[2][nColumn];
    o_vColumn.w = rc[3][nColumn];
}

inline void Matrix4x4::GetAxisX(Vector3& o_vAxis) const {
    o_vAxis.x = _11;
    o_vAxis.y = _12;
    o_vAxis.z = _13;
}

inline void Matrix4x4::GetAxisY(Vector3& o_vAxis) const {
    o_vAxis.x = _21;
    o_vAxis.y = _22;
    o_vAxis.z = _23;
}

inline void Matrix4x4::GetAxisZ(Vector3& o_vAxis) const {
    o_vAxis.x = _31;
    o_vAxis.y = _32;
    o_vAxis.z = _33;
}

inline void Matrix4x4::GetPosition(Vector3& o_vPosition) const {
    o_vPosition.x = _41;
    o_vPosition.y = _42;
    o_vPosition.z = _43;
}

inline void Matrix4x4::GetCell(RINT nRow, RINT nColumn, RFLOAT& o_nValue) const {
    o_nValue = rc[nRow][nColumn];
}

inline void Matrix4x4::Identity() {
    catMemZero(v, sizeof(v));
    _11 = 1;
    _22 = 1;
    _33 = 1;
    _44 = 1;
}

inline void Matrix4x4::Inverse() {
    auto cbCalculateMinor = [] (RFLOAT n11, RFLOAT n12, RFLOAT n13, RFLOAT n21, RFLOAT n22, RFLOAT n23, RFLOAT n31, RFLOAT n32, RFLOAT n33) {
        return n11*n22*n33 + n12*n23*n31 + n21*n32*n13 - n13*n22*n31 - n12*n21*n33 - n11*n23*n32;
    };
    Matrix4x4 mTemp;
    for(int i=0 ; i<4 ; ++i) {
        for(int j=0 ; j<4 ; ++j) {
            mTemp.rc[j][i] = static_cast<float>(pow(-1.0f, i+j)) * cbCalculateMinor(
                rc[0<i ? 0 : 1][0<j ? 0 : 1],
                rc[0<i ? 0 : 1][1<j ? 1 : 2],
                rc[0<i ? 0 : 1][2<j ? 2 : 3],
                rc[1<i ? 1 : 2][0<j ? 0 : 1],
                rc[1<i ? 1 : 2][1<j ? 1 : 2],
                rc[1<i ? 1 : 2][2<j ? 2 : 3],
                rc[2<i ? 2 : 3][0<j ? 0 : 1],
                rc[2<i ? 2 : 3][1<j ? 1 : 2],
                rc[2<i ? 2 : 3][2<j ? 2 : 3]
            );
        }
    }
    RFLOAT nOneOverDeterminant = 1.0f / (v[0] * mTemp.v[0] + v[1] * mTemp.v[4] + v[2] * mTemp.v[8] + v[3] * mTemp.v[12]);
    memcpy_s(this, sizeof(Matrix4x4), &mTemp, sizeof(Matrix4x4));
    for(int i=0 ; i<16 ; ++i) {
        v[i] *= nOneOverDeterminant;
    }
}

inline void Matrix4x4::Transpose() {
    RFLOAT nTemp(0);
    for(int i=0 ; i<4 ; ++i) {
        for(int j=0 ; j<i ; ++j) {
            nTemp = rc[j][i];
            rc[j][i] = rc[i][j];
            rc[i][j] = nTemp;
        }
    }
}

inline Matrix4x4 Matrix4x4::Inversed() const {
    Matrix4x4 m(*this);
    m.Inverse();
    return m;
}

inline Matrix4x4 Matrix4x4::Transposed() const {
    Matrix4x4 m(*this);
    m.Transpose();
    return m;
}

inline void Matrix4x4::Inversed(Matrix4x4& o_mInversed) const {
    o_mInversed = (*this);
    o_mInversed.Inverse();
}

inline void Matrix4x4::Transposed(Matrix4x4& o_mTransposed) const {
    o_mTransposed = (*this);
    o_mTransposed.Transpose();
}

inline Matrix4x4 Matrix4x4::operator*(Matrix4x4 const& mMatrix) const {
    Matrix4x4 m = Matrix4x4();
    for(int i=0 ; i<4 ; ++i) {
        for(int j=0 ; j<4 ; ++j) {
            m.v[4*i+j] = Dot(GetRow(i), mMatrix.GetColumn(j));
        }
    }
    return m;
}

inline Matrix4x4 Matrix4x4::operator*(RFLOAT nValue) const {
    Matrix4x4 m = Matrix4x4();
    for(int i=0 ; i<16 ; ++i) {
        m.v[i] = nValue * v[i];
    }
    return m;
}

inline Matrix4x4 Matrix4x4::operator+(Matrix4x4 const& mMatrix) const {
    Matrix4x4 m = Matrix4x4();
    for(int i=0 ; i<16 ; ++i) {
        m.v[i] = mMatrix.v[i] + v[i];
    }
    return m;
}

inline Matrix4x4 Matrix4x4::operator+(RFLOAT nValue) const {
    Matrix4x4 m = Matrix4x4();
    for(int i=0 ; i<16 ; ++i) {
        m.v[i] = nValue + v[i];
    }
    return m;
}

inline Matrix4x4 Matrix4x4::operator-(Matrix4x4 const& mMatrix) const {
    Matrix4x4 m = Matrix4x4();
    for(int i=0 ; i<16 ; ++i) {
        m.v[i] = mMatrix.v[i] - v[i];
    }
    return m;
}

inline Matrix4x4 Matrix4x4::operator-(RFLOAT nValue) const {
    Matrix4x4 m = Matrix4x4();
    for(int i=0 ; i<16 ; ++i) {
        m.v[i] = nValue - v[i];
    }
    return m;
}


inline Matrix4x4& Matrix4x4::operator=(Matrix4x4 const& mCopy) {
    if(this != &mCopy)
        memcpy_s(v, 16 * RFLOAT_SIZE, mCopy.v, 16 * RFLOAT_SIZE);
    
    return *this;
}

inline Matrix4x4& Matrix4x4::operator*=(Matrix4x4 const& mMatrix) {
    Matrix4x4 m = (*this);
    for(int i=0 ; i<4 ; ++i) {
        for(int j=0 ; j<4 ; ++j) {
            v[4*i+j] = Dot(m.GetRow(i), mMatrix.GetColumn(j));
        }
    }
    return (*this);
}

inline Matrix4x4& Matrix4x4::operator*=(RFLOAT nValue) {
    for(int i=0 ; i<16 ; ++i) {
        v[i] *= nValue;
    }
    return (*this);
}

inline Matrix4x4& Matrix4x4::operator+=(Matrix4x4 const& mMatrix) {
    for(int i=0 ; i<16 ; ++i) {
        v[i] += mMatrix.v[i];
    }
    return (*this);
}

inline Matrix4x4& Matrix4x4::operator+=(RFLOAT nValue) {
    for(int i=0 ; i<16 ; ++i) {
        v[i] += nValue;
    }
    return (*this);
}

inline Matrix4x4& Matrix4x4::operator-=(Matrix4x4 const& mMatrix) {
    for(int i=0 ; i<16 ; ++i) {
        v[i] -= mMatrix.v[i];
    }
    return (*this);
}

inline Matrix4x4& Matrix4x4::operator-=(RFLOAT nValue) {
    for(int i=0 ; i<16 ; ++i) {
        v[i] -= nValue;
    }
    return (*this);
}


inline Matrix4x4 Matrix4x4::CreatePerspectiveLH(RFLOAT nFOV, RFLOAT nAspectRatio, RFLOAT nNearClipping, RFLOAT nFarClipping) {
    Matrix4x4 m = Matrix4x4();
    RFLOAT nFactor = static_cast<RFLOAT>(1.0/(tan(nFOV/2.0)));
    RFLOAT nFrustrumDepth = nFarClipping - nNearClipping;
    RFLOAT nOneOverDepth = 1.0f / nFrustrumDepth;
    m._11 = nFactor/nAspectRatio;
    m._22 = nFactor;
    m._33 = nFarClipping * nOneOverDepth;
    m._43 = -nFarClipping * nNearClipping * nOneOverDepth;
    m._34 = 1;
    m._44 = 0;
    return m;
}

inline Matrix4x4 Matrix4x4::CreatePerspectiveRH(RFLOAT nFOV, RFLOAT nAspectRatio, RFLOAT nNearClipping, RFLOAT nFarClipping) {
    Matrix4x4 m = Matrix4x4();
    RFLOAT nF = static_cast<RFLOAT>(1.0/(tan(nFOV/2.0)));
    m._11 = nF/nAspectRatio;
    m._21 = nF;
    m._33 = nFarClipping / (nFarClipping - nNearClipping);
    m._34 = -1;
    m._43 = (-nNearClipping * nFarClipping) / (nFarClipping - nNearClipping);
    return m;
}

inline Matrix4x4 Matrix4x4::CreateIdentity() {
    return Matrix4x4();
}

inline Matrix4x4 Matrix4x4::CreateViewLH(Vector3 const& vPosition, Vector3 const& vLookat, Vector3 const& vUp) {
    Vector3 vZ = Normalized(vLookat - vPosition);
    Vector3 vX = Normalized(CrossLH(vZ, vUp));
    Vector3 vY = Normalized(CrossLH(vX, vZ));
    Matrix4x4 m = Matrix4x4();
    m.SetColumn(0, vX.x, vX.y, vX.z, (-vPosition).Dot(vX));
    m.SetColumn(1, vY.x, vY.y, vY.z, (-vPosition).Dot(vY));
    m.SetColumn(2, vZ.x, vZ.y, vZ.z, (-vPosition).Dot(vZ));
    return m;
}

inline Matrix4x4 Matrix4x4::CreateViewRH(Vector3 const& vPosition, Vector3 const& vLookat, Vector3 const& vUp) {
    Vector3 vZ = Normalized(vLookat - vPosition);
    Vector3 vX = Normalized(CrossRH(vZ, vUp));
    Vector3 vY = Normalized(CrossRH(vX, vZ));
    Matrix4x4 m = Matrix4x4();
    m.SetColumn(0, vX.x, vX.y, vX.z, (-vPosition).Dot(vX));
    m.SetColumn(1, vY.x, vY.y, vY.z, (-vPosition).Dot(vY));
    m.SetColumn(2, vZ.x, vZ.y, vZ.z, (-vPosition).Dot(vZ));
    return m;
}

inline Matrix4x4 Matrix4x4::CreateScale(Vector3 const& vScale) {
    Matrix4x4 m = Matrix4x4();
    m._11 = vScale.x;
    m._22 = vScale.y;
    m._33 = vScale.z;
    return m;
}

inline Matrix4x4 Matrix4x4::CreateTranslate(Vector3 const& vTranslation) {
    Matrix4x4 m = Matrix4x4();
    m.SetPosition(vTranslation);
    return m;
}

inline Matrix4x4 Matrix4x4::CreateRotateX(RFLOAT nRot) {
    RDOUBLE nRad = (RDOUBLE)nRot * RAD2DEG;
    Matrix4x4 m = Matrix4x4();
    m._22 = (RFLOAT)cos(nRad);
    m._23 = (RFLOAT)sin(nRad);
    m._32 = (RFLOAT)-sin(nRad);
    m._33 = (RFLOAT)cos(nRad);
    return m;
}

inline Matrix4x4 Matrix4x4::CreateRotateY(RFLOAT nRot) {
    RDOUBLE nRad = (RDOUBLE)nRot * RAD2DEG;
    Matrix4x4 m = Matrix4x4();
    m._11 = (RFLOAT)cos(nRad);
    m._13 = (RFLOAT)-sin(nRad);
    m._31 = (RFLOAT)sin(nRad);
    m._33 = (RFLOAT)cos(nRad);
    return m;
}

inline Matrix4x4 Matrix4x4::CreateRotateZ(RFLOAT nRot) {
    RDOUBLE nRad = (RDOUBLE)nRot * RAD2DEG;
    Matrix4x4 m = Matrix4x4();
    m._22 = (RFLOAT)cos(nRad);
    m._23 = (RFLOAT)sin(nRad);
    m._32 = (RFLOAT)-sin(nRad);
    m._33 = (RFLOAT)cos(nRad);
    return m;
}