#include "Rock_Std.h"
#include "Rock_Vector.h"

using namespace Rock;

Vector1 v1A;
Vector1 v1B(1);
Vector2 v2A;
Vector2 v2B(1);
Vector2 v2C(1, 2);
Vector3 v3A;
Vector3 v3B(1);
Vector3 v3C(1, 2, 3);
Vector4 v4A;
Vector4 v4B(1);
Vector4 v4C(1, 2, 3, 4);

void Main() {
	float nLength = Length(v4C);
	float nDot = Dot(v4B, v4C);
	float nDistance = Distance(v4A, v4B);
	RBOOL b0 = v4A < 5;
	RBOOL b1 = v4A < v4B;
	RBOOL b2 = v4A > 5;
	RBOOL b3 = v4A > v4B;
	RBOOL b4 = v4A <= 5;
	RBOOL b5 = v4A <= v4B;
	RBOOL b6 = v4A >= 5;
	RBOOL b7 = v4A >= v4B;

	v4A[3] = v4C[2];

	v4A = v4B + 4;
	v4A = v4B + v4C;
	v4B += v4A;
	v4B += 4;

	v4A = v4B - 4;
	v4A = v4B - v4C;
	v4B -= v4A;
	v4B -= 4;

	v4A = v4B * 4;
	v4A = v4B * v4C;
	v4B *= v4A;
	v4B *= 4;

	v4A = v4B / 4;
	v4A = v4B / v4C;
	v4B /= v4A;
	v4B /= 4;

    v3A = CrossLh(v3B, v3C);
    v3A = CrossRh(v3B, v3C);

    Vector<double, 5> tmp;

    double a[5] = {1, 2, 3, 4, 5};
    auto v = Vector<double, 5>(a);
    auto t = v[6];

}