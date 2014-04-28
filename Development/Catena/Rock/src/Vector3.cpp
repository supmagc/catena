#include "Rock_Std.h"
#include "Rock_Vector3.h"
#include "Rock_Types.h"

using namespace Rock;

Vector3::Vector3() {
    ZERO(this, sizeof(Vector3));
}

Vector3::Vector3(RFLOAT v) : x(v), y(v), z(v) {
}

Vector3::Vector3(RFLOAT x, RFLOAT y, RFLOAT z) : x(x), y(y), z(z) {
}

Vector3::Vector3(Vector3 const& vCopy) : x(vCopy.x), y(vCopy.y), z(vCopy.z) {
}

Vector3::~Vector3() {
}

inline void Vector3::Normalize() {
    RFLOAT nLength = Length();
    if(0 != nLength) {
        x /= nLength;
        y /= nLength;
        z /= nLength;
    }
}

inline Vector3 Vector3::Normalized() const {
    RFLOAT nLength = Length();
    if(0 != nLength)
        return Vector3(x/nLength, y/nLength, z/nLength);
    else
        return Vector3();
}

inline RFLOAT Vector3::Length() const {
    return sqrt(LengthSq());
}

inline RFLOAT Vector3::LengthSq() const {
    return x*x + y*y + z*z;
}

inline RFLOAT Vector3::Distance(Vector3 const& vVector) const {
    return Rock::Length((*this) - vVector);
}

inline RFLOAT Vector3::Dot(Vector3 const& vVector) const {
    return x*vVector.x + y*vVector.y + z*vVector.z;
}

inline Vector3 Vector3::CrossLH(Vector3 const& vVector) const {
    return Vector3(z*vVector.y - y*vVector.z, x*vVector.z - z*vVector.x, y*vVector.x - x*vVector.y);
}

inline Vector3 Vector3::CrossRH(Vector3 const& vVector) const {
    return Vector3(y*vVector.z - z*vVector.y, z*vVector.x - x*vVector.z, x*vVector.y - y*vVector.x);
}

inline void Vector3::Normalized(Vector3& o_vNormalized) const {
    RFLOAT nLength = Length();
    if(0 != nLength) {
        o_vNormalized.x = x / nLength;
        o_vNormalized.y = y / nLength;
        o_vNormalized.z = z / nLength;
    }
    else {
        o_vNormalized.x = 0;
        o_vNormalized.y = 0;
        o_vNormalized.z = 0;
    }
}

inline void Vector3::Length(RFLOAT& o_nLength) const {
    o_nLength = sqrtf(x*x + y*y + z*z);
}

inline void Vector3::LengthSq(RFLOAT& o_nLength) const {
    o_nLength = x*x + y*y + z*z;
}

inline void Vector3::Distance(Vector3 const& vVector, RFLOAT& o_nDistance) const {
    o_nDistance = Rock::Length((*this) - vVector);
}

inline void Vector3::Dot(Vector3 const& vVector, RFLOAT& o_nDot) const {
    o_nDot = x*vVector.x + y*vVector.y + z*vVector.z;
}

inline void Vector3::CrossLH(Vector3 const& vVector, Vector3& o_vCross) const {
    o_vCross.x = z*vVector.y - y*vVector.z;
    o_vCross.y = x*vVector.z - z*vVector.x;
    o_vCross.z = y*vVector.x - x*vVector.y;
}

inline void Vector3::CrossRH(Vector3 const& vVector, Vector3& o_vCross) const {
    o_vCross.x = y*vVector.z - z*vVector.y;
    o_vCross.y = z*vVector.x - x*vVector.z;
    o_vCross.z = x*vVector.y - y*vVector.x;
}

inline RBOOL Vector3::operator<(RFLOAT nValue) const {
    return LengthSq() < nValue*nValue;
}

inline RBOOL Vector3::operator>(RFLOAT nValue) const {
    return LengthSq() > nValue*nValue;
}

inline RBOOL Vector3::operator<(Vector3 const& vVector) const {
    return LengthSq() < vVector.LengthSq();
}

inline RBOOL Vector3::operator>(Vector3 const& vVector) const {
    return LengthSq() > vVector.LengthSq();
}

inline Vector3 Vector3::operator-() const {
    return Vector3(-x, -y, -z);
}

inline Vector3 Vector3::operator+(Vector3 const& vVector) const {
    return Vector3(x + vVector.x, y + vVector.y, z + vVector.z);
}

inline Vector3 Vector3::operator-(Vector3 const& vVector) const {
    return Vector3(x - vVector.x, y - vVector.y, z - vVector.z);
}

inline Vector3 Vector3::operator*(RFLOAT nValue) const {
    return Vector3(x * nValue, y * nValue, z * nValue);
}

inline Vector3 Vector3::operator/(RFLOAT nValue) const {
    return Vector3(x / nValue, y / nValue, z / nValue);
}

Vector3& Vector3::operator=(Vector3 const& vVector) {
    if(this != &vVector) {
        memcpy_s(this, sizeof(Vector3), &vVector, sizeof(Vector3));
    }
    return (*this);
}

inline Vector3& Vector3::operator+=(Vector3 const& vVector) {
    x += vVector.x;
    y += vVector.y;
    z += vVector.z;
    return (*this);
}

inline Vector3& Vector3::operator-=(Vector3 const& vVector) {
    x -= vVector.x;
    y -= vVector.y;
    z -= vVector.z;
    return (*this);
}

inline Vector3& Vector3::operator*=(RFLOAT nValue) {
    x *= nValue;
    y *= nValue;
    z *= nValue;
    return (*this);
}

inline Vector3& Vector3::operator/=(RFLOAT nValue) {
    x /= nValue;
    y /= nValue;
    z /= nValue;
    return (*this);
}

inline ROCK_API Vector3 Rock::Normalized(Vector3 const& vVector) {
    return vVector.Normalized();
}

inline ROCK_API RFLOAT Rock::Length(Vector3 const& vVector) {
    return vVector.Length();
}

inline ROCK_API RFLOAT Rock::LengthSq(Vector3 const& vVector) {
    return vVector.LengthSq();
}

inline ROCK_API RFLOAT Rock::Distance(Vector3 const& vVector0, Vector3 const& vVector1) {
    return Length(vVector0 - vVector1);
}

inline ROCK_API RFLOAT Rock::Dot(Vector3 const& vVector0, Vector3 const& vVector1) {
    return LengthSq(vVector0 - vVector1);
}

inline ROCK_API Vector3 Rock::CrossLH(Vector3 const& vVector0, Vector3 const& vVector1) {
    return vVector0.CrossLH(vVector1);
}

inline ROCK_API Vector3 Rock::CrossRH(Vector3 const& vVector0, Vector3 const& vVector1) {
    return vVector0.CrossRH(vVector1);
}

inline ROCK_API void Rock::Normalized(Vector3 const& vVector, Vector3& o_vNormalized) {
    vVector.Normalized(o_vNormalized);
}

inline ROCK_API void Rock::Length(Vector3 const& vVector, RFLOAT& o_nLength) {
    vVector.Length(o_nLength);
}

inline ROCK_API void Rock::LengthSq(Vector3 const& vVector, RFLOAT& o_nLengthSq) {
    vVector.LengthSq(o_nLengthSq);
}

inline ROCK_API void Rock::Distance(Vector3 const& vVector0, Vector3 const& vVector1, RFLOAT& o_nDistance) {
    vVector0.Distance(vVector1, o_nDistance);
}

inline ROCK_API void Rock::Dot(Vector3 const& vVector0, Vector3 const& vVector1, RFLOAT& o_nDot) {
    vVector0.Dot(vVector1, o_nDot);
}

inline ROCK_API void Rock::CrossLH(Vector3 const& vVector0, Vector3 const& vVector1, Vector3& o_vCross) {
    vVector0.CrossLH(vVector1, o_vCross);
}

inline ROCK_API void Rock::CrossRH(Vector3 const& vVector0, Vector3 const& vVector1, Vector3& o_vCross) {
    vVector0.CrossRH(vVector1, o_vCross);
}

inline ROCK_API RBOOL operator<(RFLOAT nValue, Vector3 const& vVector) {
    return nValue*nValue < vVector.LengthSq();
}

inline ROCK_API RBOOL operator>(RFLOAT nValue, Vector3 const& vVector) {
    return nValue*nValue > vVector.LengthSq();
}

inline ROCK_API Vector3 operator*(RFLOAT nValue, Vector3 const& vVector) {
    return vVector * nValue;
}

inline ROCK_API Vector3 operator/(RFLOAT nValue, Vector3 const& vVector) {
    return vVector * (1.0f/nValue);
}
