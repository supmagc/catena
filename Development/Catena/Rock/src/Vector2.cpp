#include "Rock_Std.h"
#include "Rock_Vector2.h"
#include "Rock_Types.h"

using namespace Rock;

Vector2::Vector2() {
    ZERO(this, sizeof(Vector2));
}

Vector2::Vector2(RFLOAT v) : x(v), y(v) {
}

Vector2::Vector2(RFLOAT x, RFLOAT y) : x(x), y(y) {
}

Vector2::Vector2(Vector2 const& vCopy) : x(vCopy.x), y(vCopy.y) {
}

Vector2::~Vector2() {
}

Vector2& Vector2::operator=(Vector2 const& vCopy) {
    return (*this);
}