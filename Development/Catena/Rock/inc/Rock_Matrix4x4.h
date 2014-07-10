#ifndef _H_ROCK_MATRIX4X4
#define _H_ROCK_MATRIX4X4

#include "Rock_Types.h"
#include "Rock_Vector3.h"
#include "Rock_Vector4.h"
#include "Rock_Functions.h"

namespace Rock {

    #pragma pack(16)
    struct DLL_EXPORT Matrix4x4 {

        union {
            struct {
                RFLOAT _11, _12, _13, _14;
                RFLOAT _21, _22, _23, _24;
                RFLOAT _31, _32, _33, _34;
                RFLOAT _41, _42, _43, _44;
            };
            RFLOAT rc[4][4];
            RFLOAT v[16];
        };

        Matrix4x4();
        Matrix4x4(Matrix4x4 const& mCopy);
        ~Matrix4x4();

        INLINE void SetRow(RINT const nRow, Vector4 const& vRow);
        INLINE void SetRow(RINT const nRow, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3);
        INLINE void SetColumn(RINT const nColumn, Vector4 const& vColumn);
        INLINE void SetColumn(RINT const nColumn, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3);
        INLINE void SetAxisX(Vector3 const& vAxis);
        INLINE void SetAxisX(RFLOAT x, RFLOAT y, RFLOAT z);
        INLINE void SetAxisY(Vector3 const& vAxis);
        INLINE void SetAxisY(RFLOAT x, RFLOAT y, RFLOAT z);
        INLINE void SetAxisZ(Vector3 const& vAxis);
        INLINE void SetAxisZ(RFLOAT x, RFLOAT y, RFLOAT z);
        INLINE void SetPosition(Vector3 const& vPosition);
        INLINE void SetPosition(RFLOAT x, RFLOAT y, RFLOAT z);
        INLINE void SetCell(RINT nRow, RINT nColumn, RFLOAT nCell);

        INLINE Vector4 GetRow(RINT nRow) const;
        INLINE Vector4 GetColumn(RINT nColumn) const;
        INLINE Vector3 GetAxisX() const;
        INLINE Vector3 GetAxisY() const;
        INLINE Vector3 GetAxisZ() const;
        INLINE Vector3 GetPosition() const;
        INLINE RFLOAT GetCell(RINT nRow, RINT nColumn) const;
        INLINE void GetRow(RINT nRow, Vector4& o_vRow) const;
        INLINE void GetColumn(RINT nColumn, Vector4& o_vColumn) const;
        INLINE void GetAxisX(Vector3& o_vAxis) const;
        INLINE void GetAxisY(Vector3& o_vAxis) const;
        INLINE void GetAxisZ(Vector3& o_vAxis) const;
        INLINE void GetPosition(Vector3& o_vPosition) const;
        INLINE void GetCell(RINT nRow, RINT nColumn, RFLOAT& o_nValue) const;

        INLINE void Identity();
        INLINE void Inverse();
        INLINE void Transpose();
        INLINE Matrix4x4 Inversed() const;
        INLINE Matrix4x4 Transposed() const;
        INLINE void Inversed(Matrix4x4& o_mInversed) const;
        INLINE void Transposed(Matrix4x4& o_mTransposed) const;

        //void TransformVector(Vector4 const& vIn, Vector4& o_vValue) const;
        //Vector4 TransformVector(Vector4 const& vIn) const;

        INLINE Matrix4x4 operator*(Matrix4x4 const& mMatrix) const;
        INLINE Matrix4x4 operator*(RFLOAT nValue) const;
        INLINE Matrix4x4 operator+(Matrix4x4 const& mMatrix) const;
        INLINE Matrix4x4 operator+(RFLOAT nValue) const;
        INLINE Matrix4x4 operator-(Matrix4x4 const& mMatrix) const;
        INLINE Matrix4x4 operator-(RFLOAT nValue) const;
        INLINE Matrix4x4& operator=(Matrix4x4 const& mMatrix);
        INLINE Matrix4x4& operator*=(Matrix4x4 const& mMatrix);
        INLINE Matrix4x4& operator*=(RFLOAT nValue);
        INLINE Matrix4x4& operator+=(Matrix4x4 const& mMatrix);
        INLINE Matrix4x4& operator+=(RFLOAT nValue);
        INLINE Matrix4x4& operator-=(Matrix4x4 const& mMatrix);
        INLINE Matrix4x4& operator-=(RFLOAT nValue);

        //Matrix4x4& Scale(RVector3 vIn);
        //Matrix4x4& Translate(RCVector3 vIn);
        //Matrix4x4& RotateX(CFloat32 nRot);
        //Matrix4x4& RotateY(CFloat32 nRot);
        //Matrix4x4& RotateZ(CFloat32 nRot);
        //Matrix4x4& RotateAxis(RCVector3 vIn, CFloat32 nRot);

        static INLINE Matrix4x4 CreatePerspectiveLH(RFLOAT nFOV, RFLOAT nAspectRatio, RFLOAT nNearClipping, RFLOAT nFarClipping);
        static INLINE Matrix4x4 CreatePerspectiveRH(RFLOAT nFOV, RFLOAT nAspectRatio, RFLOAT nNearClipping, RFLOAT nFarClipping);
        static INLINE Matrix4x4 CreateIdentity();
        static INLINE Matrix4x4 CreateViewLH(Vector3 const& vPosition, Vector3 const& vLookat, Vector3 const& vUp);
        static INLINE Matrix4x4 CreateViewRH(Vector3 const& vPosition, Vector3 const& vLookat, Vector3 const& vUp);
        static INLINE Matrix4x4 CreateScale(Vector3 const& vScale);
        static INLINE Matrix4x4 CreateTranslate(Vector3 const& vTranslation);
        static INLINE Matrix4x4 CreateRotateX(RFLOAT nRot);
        static INLINE Matrix4x4 CreateRotateY(RFLOAT nRot);
        static INLINE Matrix4x4 CreateRotateZ(RFLOAT nRot);
    };

    typedef Matrix4x4 RMatrix4x4;
    typedef Matrix4x4 Matrix;
    typedef Matrix RMatrix;

    #include "../inl/Matrix4x4.inl"
};

#endif // _H_ROCK_MATRIX4X4