#include "Rock_Std.h"
#include "Rock_Array.h"

using namespace Rock;

void Test() {
    int* a = new int[2]();
    a[0] = 4;
    a[1] = 8;
    Array<int> lData0 = Array<int>(8, 4);
    Array<int> lData1(lData0);
    Array<int> lData2({2, 4, 8});
    Array<int> lData3(a, 2);
    int n = lData0[2];
    Array<int> lData4 = lData3;

    RUINT nIndex;
    lData0.Push(1);
    lData0.Push(2);
    lData0.Push(4);
    lData0.Push(8);
    lData0.Push(lData2);
    lData0.Peek();
    lData0.Peek(2);
    lData0.Pop();
    lData0.Pop(2);
    lData0.Clear();
    lData0.FirstIndexOf(16, nIndex);
    lData0.LastIndexOf(16, nIndex);
    //   lData0.Insert(16, 0);
    lData0.RemoveElement(16);
    lData0.RemoveIndex(0);
    lData0.Increase(4);
    lData0.Decrease(2);
    lData0.Resize(8);

    lData0[0] = 5;
    delete[] a;
}