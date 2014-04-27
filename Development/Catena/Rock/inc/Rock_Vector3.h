#ifndef _H_ROCK_VECTOR3
#define _H_ROCK_VECTOR3

#include "Rock_Types.h"

namespace Rock {

    struct ROCK_API Vector3 {

        RFLOAT x, y, z;

        Vector3();
        Vector3(RFLOAT v);
        Vector3(RFLOAT x, RFLOAT y, RFLOAT z);
        Vector3(Vector3 const& vCopy);
        ~Vector3();

        inline void Normalize();
        inline Vector3 Normalized() const;
        inline RFLOAT Length() const;
        inline RFLOAT LengthSq() const;
        inline RFLOAT Distance(Vector3 const& vVector) const;
        inline RFLOAT Dot(Vector3 const& vVector) const;
        inline Vector3 Cross(Vector3 const& vVector) const;
        inline void Normalized(Vector3& o_vNormalized) const;
        inline void Length(RFLOAT& o_nLength) const;
        inline void LengthSq(RFLOAT& o_nLength) const;
        inline void Distance(Vector3 const& vVector, RFLOAT& o_nDistance) const;
        inline void Dot(Vector3 const& vVector, RFLOAT& o_nDot) const;
        inline void Cross(Vector3 const& vVector, Vector3& o_vCross) const;

        inline RBOOL operator<(RFLOAT nValue) const;
        inline RBOOL operator>(RFLOAT nValue) const;
        inline RBOOL operator<(Vector3 const& vVector) const;
        inline RBOOL operator>(Vector3 const& vVector) const;
        inline Vector3 operator+(Vector3 const& vVector) const;
        inline Vector3 operator-(Vector3 const& vVector) const;
        inline Vector3 operator*(RFLOAT nValue) const;
        inline Vector3 operator/(RFLOAT nValue) const;
        inline Vector3& operator=(Vector3 const& vVector);
        inline Vector3& operator+=(Vector3 const& vVector);
        inline Vector3& operator-=(Vector3 const& vVector);
        inline Vector3& operator*=(RFLOAT nValue);
        inline Vector3& operator/=(RFLOAT nValue);
    };

    inline ROCK_API Vector3 Normalized(Vector3 const& vVector);
    inline ROCK_API RFLOAT Length(Vector3 const& vVector);
    inline ROCK_API RFLOAT LengthSq(Vector3 const& vVector);
    inline ROCK_API RFLOAT Distance(Vector3 const& vVector0, Vector3 const& vVector1);
    inline ROCK_API RFLOAT Dot(Vector3 const& vVector0, Vector3 const& vVector1);
    inline ROCK_API Vector3 Cross(Vector3 const& vVector0, Vector3 const& vVector1);

    inline ROCK_API RBOOL operator<(RFLOAT nValue, Vector3 const& vVector);
    inline ROCK_API RBOOL operator>(RFLOAT nValue, Vector3 const& vVector);
    inline ROCK_API Vector3 operator*(RFLOAT nValue, Vector3 const& vVector);
    inline ROCK_API Vector3 operator/(RFLOAT nValue, Vector3 const& vVector);

    typedef Vector3 RVector3;
    typedef Vector3 Vector;
    typedef Vector RVector;
};

#endif // _H_ROCK_VECTOR3