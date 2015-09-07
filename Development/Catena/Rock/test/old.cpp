
#include "Rock.h"
using namespace std;
using namespace Rock;

void Test_Matrix();
void Test_Vector();

void Test_Print(RCHAR *const format, va_list args)
{
	_vscwprintf(format, args);
	vwprintf(format, args);
}

void Test_Print(RCHAR *const format, ...)
{
	va_list args;
	va_start(args, format);
	Test_Print(format, args);
	va_end(args);
}

/*int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR pCmdLine, int nCmdShow) {
	StringBuilder sb;
	sb << RTXT("1.0");
	LOG_INFO(sb.ToString());
	wprintf(RTXT("Vector%i(%s)"), 5, sb.ToString());
	Test_Print(RTXT("Vector%i"), 5);
	Test_Vector();
	Test_Matrix();
}*/

Matrix33 m33A = Matrix33();
Matrix33 m33B = Matrix33();
Matrix44 m44A = Matrix44();
Matrix44 m44B = Matrix44();

struct A {
	A(int, int) {}
};

struct B : A {
	B(int) : A(0, 0) {}
	using A::A;
};

void Test_Matrix() {

	B* b = new B(0, 1);

	m44A[2][1] = m44B[0][2];
	m44B = Matrix44(Vector3(), Vector3(), Vector3(), Vector3(), 2);

	auto tmp0 = Matrix<RFLOAT, 2, 6>::Identity();
	auto tmp1 = Matrix<RFLOAT, 6, 6>::Identity();
	auto tmp2 = Matrix<RFLOAT, 6, 2>::Identity();

	//auto tmp = MakeIdentity<RFLOAT>(5, 5);
}


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

template<typename T>
class Tester {
public:
	INLINE T Test(T const& n) const;
};

template<typename T>
INLINE T Tester<T>::Test(T const& n) const {
	return n;
}

void Test_Vector() {
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

	auto n0 = v4A.Length();
	auto n1 = v4A.LengthSq();
	v4B = v4A.Normalize();

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
	std::cout << tmp.ToString();

	double a[5] = { 1, 2, 3, 4, 5 };
	auto v = Vector<double, 5>(a);
}