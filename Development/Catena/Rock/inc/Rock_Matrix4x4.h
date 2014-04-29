#ifndef _H_ROCK_MATRIX4X4
#define _H_ROCK_MATRIX4X4

#include "Rock_Types.h"
#include "Rock_Vector3.h"
#include "Rock_Vector4.h"

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

        inline void SetRow(RINT const nRow, Vector4 const& vRow);
        inline void SetRow(RINT const nRow, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3);
        inline void SetColumn(RINT const nColumn, Vector4 const& vColumn);
        inline void SetColumn(RINT const nColumn, RFLOAT n0, RFLOAT n1, RFLOAT n2, RFLOAT n3);
        inline void SetAxisX(Vector3 const& vAxis);
        inline void SetAxisX(RFLOAT x, RFLOAT y, RFLOAT z);
        inline void SetAxisY(Vector3 const& vAxis);
        inline void SetAxisY(RFLOAT x, RFLOAT y, RFLOAT z);
        inline void SetAxisZ(Vector3 const& vAxis);
        inline void SetAxisZ(RFLOAT x, RFLOAT y, RFLOAT z);
        inline void SetPosition(Vector3 const& vPosition);
        inline void SetPosition(RFLOAT x, RFLOAT y, RFLOAT z);
        inline void SetCell(RINT nRow, RINT nColumn, RFLOAT nCell);

        inline Vector4 GetRow(RINT nRow) const;
        inline Vector4 GetColumn(RINT nColumn) const;
        inline Vector3 GetAxisX() const;
        inline Vector3 GetAxisY() const;
        inline Vector3 GetAxisZ() const;
        inline Vector3 GetPosition() const;
        inline RFLOAT GetCell(RINT nRow, RINT nColumn) const;
        inline void GetRow(RINT nRow, Vector4& o_vRow) const;
        inline void GetColumn(RINT nColumn, Vector4& o_vColumn) const;
        inline void GetAxisX(Vector3& o_vAxis) const;
        inline void GetAxisY(Vector3& o_vAxis) const;
        inline void GetAxisZ(Vector3& o_vAxis) const;
        inline void GetPosition(Vector3& o_vPosition) const;
        inline void GetCell(RINT nRow, RINT nColumn, RFLOAT& o_nValue) const;

        inline void Identity();
        inline void Inverse();
        inline void Transpose();
        inline Matrix4x4 Inversed() const;
        inline Matrix4x4 Transposed() const;
        inline void Inversed(Matrix4x4& o_mInversed) const;
        inline void Transposed(Matrix4x4& o_mTransposed) const;

        //void TransformVector(Vector4 const& vIn, Vector4& o_vValue) const;
        //Vector4 TransformVector(Vector4 const& vIn) const;

        inline Matrix4x4 operator*(Matrix4x4 const& mMatrix) const;
        inline Matrix4x4 operator*(RFLOAT nValue) const;
        inline Matrix4x4 operator+(Matrix4x4 const& mMatrix) const;
        inline Matrix4x4 operator+(RFLOAT nValue) const;
        inline Matrix4x4 operator-(Matrix4x4 const& mMatrix) const;
        inline Matrix4x4 operator-(RFLOAT nValue) const;
        inline Matrix4x4& operator=(Matrix4x4 const& mMatrix);
        inline Matrix4x4& operator*=(Matrix4x4 const& mMatrix);
        inline Matrix4x4& operator*=(RFLOAT nValue);
        inline Matrix4x4& operator+=(Matrix4x4 const& mMatrix);
        inline Matrix4x4& operator+=(RFLOAT nValue);
        inline Matrix4x4& operator-=(Matrix4x4 const& mMatrix);
        inline Matrix4x4& operator-=(RFLOAT nValue);

        //Matrix4x4& Scale(RVector3 vIn);
        //Matrix4x4& Translate(RCVector3 vIn);
        //Matrix4x4& RotateX(CFloat32 nRot);
        //Matrix4x4& RotateY(CFloat32 nRot);
        //Matrix4x4& RotateZ(CFloat32 nRot);
        //Matrix4x4& RotateAxis(RCVector3 vIn, CFloat32 nRot);

        static Matrix4x4 CreatePerspectiveLH(RFLOAT nFOV, RFLOAT nAspectRatio, RFLOAT nNearClipping, RFLOAT nFarClipping);
        static Matrix4x4 CreatePerspectiveRH(RFLOAT nFOV, RFLOAT nAspectRatio, RFLOAT nNearClipping, RFLOAT nFarClipping);
        static Matrix4x4 CreateIdentity();
        static Matrix4x4 CreateViewLH(Vector3 const& vPosition, Vector3 const& vLookat, Vector3 const& vUp);
        static Matrix4x4 CreateViewRH(Vector3 const& vPosition, Vector3 const& vLookat, Vector3 const& vUp);
        static Matrix4x4 CreateScale(Vector3 const& vScale);
        static Matrix4x4 CreateTranslate(Vector3 const& vTranslation);
        static Matrix4x4 CreateRotateX(RFLOAT nRot);
        static Matrix4x4 CreateRotateY(RFLOAT nRot);
        static Matrix4x4 CreateRotateZ(RFLOAT nRot);
    };

    typedef Matrix4x4 RMatrix4x4;
    typedef Matrix4x4 Matrix;
    typedef Matrix RMatrix;
};

#endif // _H_ROCK_MATRIX4X4