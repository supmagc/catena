#include "Rock_Std.h"
#include "Rock_Vector.h"

using namespace Rock;

Vec2 v2A();
Vec2 v2B(1);
Vec2 v2C(1, 2);
Vec3 v3A();
Vec3 v3B(1);
Vec3 v3C(1, 2, 3);
Vec4 v4A = Vec4();
Vec4 v4B(1);
Vec4 v4C(1, 2, 3, 4);

template<typename t>
void test(Vector<t, 2> v, t n) { v[0] *= n; }

void Main() {
	test(v2B, 2.0f);

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
}