#include "Rock_Std.h"
#include "Rock_Array.h"

using namespace Rock;

void Test() {
	int* a = new int[2]();
	a[0] = 4;
	a[1] = 8;
    Array<int> lData0 = Array<int>(8, 4);
	Array<int> lData1(lData0);
	Array<int> lData2({ 2, 4, 8 });
	Array<int> lData3(a, 2);

	lData0.Push(1);
	lData0.Push(2);
	lData0.Push(4);
	lData0.Push(8);
	lData0.Push(lData2);
	delete[] a;
}