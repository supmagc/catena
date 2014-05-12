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