#include "Rock_Std.h"
#include "Rock_Vector3.h"
#include "Rock_Vector4.h"
#include "Rock_Types.h"

using namespace Rock;

Vector4::Vector4() {
    ZERO(this, sizeof(Vector4));
}

Vector4::Vector4(RFLOAT v) : x(v), y(v), z(v), w(v) {
}

Vector4::Vector4(RFLOAT x, RFLOAT y, RFLOAT z, RFLOAT w) : x(x), y(y), z(z), w(w) {
}

Vector4::Vector4(Vector3 const& vVector, RFLOAT w) : x(vVector.x), y(vVector.y), z(vVector.z), w(w) {
}

Vector4::Vector4(Vector4 const& vVector) : x(vVector.x), y(vVector.y), z(vVector.z), w(vVector.w) {
}

Vector4::~Vector4() {
}

inline RFLOAT Vector4::Dot(Vector4 const& vVector) const {
    return x*vVector.x + y*vVector.y + z*vVector.z + w*vVector.w;
}

inline void Vector4::Dot(Vector4 const& vVector, RFLOAT& o_nDot) const {
    o_nDot = Dot(vVector);
}

inline Vector4& Vector4::operator=(Vector4 const& vVector) {
    if(this != &vVector) {
        memcpy_s(this, sizeof(Vector4), &vVector, sizeof(Vector4));
    }
    return (*this);
}

inline ROCK_API RFLOAT Rock::Dot(Vector4 const& vVector0, Vector4 const& vVector1) {
    return vVector0.Dot(vVector1);
}
