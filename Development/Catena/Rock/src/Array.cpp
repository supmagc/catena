#include "Rock_Std.h"
#include "Rock_Array.h"

using namespace Rock;

void Test() {
    Array<int> lData = Array<int>(8, 4);
    lData.Push(2);
    lData.Push(4);
    lData.Push(8);
    lData.Pop();
    lData.Pop(2);
    lData.Peek();
    lData.Peek(2);
    int n = lData[2];
}