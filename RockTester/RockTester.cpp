// RockTester.cpp : Defines the entry point for the console application.
//
#include "Rock.h"
#include <iostream>
#include <tchar.h>

using namespace std;
using namespace Rock;

UInt32 failures = 0;

void OnReceive(void* pSender, int num) {
	wcout << num << endl;
}
class Test{
public: 
	void OnReceive(void* pSender, int num) {
		wcout << num << endl;
	}
};

void STR_ShowResult(wchar_t const* sType, Bool result) {
	wcout << sType << L":\t" << (result ? L"SUCCES" : L"FAILURE") << endl;
	if(!result){
		++failures;
	}
}

void STR_CheckStringAndLength(wchar_t const* sType, String const& sInput, wchar_t const* sOutput, Int32 nLength) {
	STR_ShowResult(sType, (sInput == String(sOutput) && sInput.GetLength() == nLength));
}

void STR_Test() {
	wcout << "Testing STR:" << endl << "-------------" << endl;
	STR_CheckStringAndLength(L"Empty constructor", String(), L"", 0);
	STR_CheckStringAndLength(L"Constructor", String(L"Hello world!"), L"Hello world!", 12);
	STR_CheckStringAndLength(L"Substring A", String(L"Hello world!").SubString(6), L"world!", 6);
	STR_CheckStringAndLength(L"Substring B", String(L"Hello world!").SubString(6, 5), L"world", 5);
	STR_CheckStringAndLength(L"Substring C", String(L"Hello world!").SubString(20, 10), L"", 0);
	STR_ShowResult(L"Beginswith A", String(L"Hello world!").BeginsWith(String(L"Hello")));
	STR_ShowResult(L"Endswith A", String(L"Hello world!").EndsWith(String(L"!")));
	STR_ShowResult(L"Beginswith B", String(L"123Hello world!").BeginsWith(123));
	STR_ShowResult(L"Endswith B", String(L"Hello world!-0.5").EndsWith(-0.5));
	STR_CheckStringAndLength(L"Appending", String(L"Hello") + String(L" world!"), L"Hello world!", 12);
	STR_CheckStringAndLength(L"SingleByte", String("Hello world!"), L"Hello world!", 12);
	STR_CheckStringAndLength(L"Int8", String(-128), L"-128", 4);
	STR_CheckStringAndLength(L"Int16", String(-32768), L"-32768", 6);
	STR_CheckStringAndLength(L"Int32", String(-2147483647), L"-2147483647", 11);
	STR_CheckStringAndLength(L"Int64", String(-9223372036854775807), L"-9223372036854775807", 20);
	STR_CheckStringAndLength(L"UInt8", String((UInt8)255), L"255", 3);
	STR_CheckStringAndLength(L"UInt16", String((UInt16)65535), L"65535", 5);
	STR_CheckStringAndLength(L"UInt32", String((UInt32)4294967295), L"4294967295", 10);
	STR_CheckStringAndLength(L"UInt64", String((UInt64)18446744073709551615), L"18446744073709551615", 20);
	//STR_CheckStringAndLength(L"Float32", String(-15.26587f), L"-15.26587", 9); // This can't be tested for accuracy :(
	STR_CheckStringAndLength(L"Float64", String(-15.26535687), L"-15.26535687", 12);
	STR_CheckStringAndLength(L"Bool", String(true), L"1", 1);
	STR_CheckStringAndLength(L"ToUpper", String(L"Hello world!").ToUpper(), L"HELLO WORLD!", 12);
	STR_CheckStringAndLength(L"ToLower", String(L"Hello world!").ToLower(), L"hello world!", 12);
	STR_CheckStringAndLength(L"Trim", String(L" Hello world!\n\r").Trim(), L"Hello world!", 12);
	STR_ShowResult(L"vv Int8", String(-128).ToInt8() == -128);
	STR_ShowResult(L"vv Int16", String(-32768).ToInt16() == -32768);
	STR_ShowResult(L"vv Int32", String(-2147483647).ToInt32() == -2147483647);
	STR_ShowResult(L"vv Int64", String(-9223372036854775807).ToInt64() == -9223372036854775807);
	STR_ShowResult(L"vv UInt8", String((UInt8)255).ToUInt8() == 255);
	STR_ShowResult(L"vv UInt16", String((UInt16)65535).ToUInt16() == 65535);
	STR_ShowResult(L"vv UInt32", String((UInt32)4294967295).ToUInt32() == 4294967295);
	STR_ShowResult(L"vv UInt64", String((UInt64)18446744073709551615).ToUInt64() == 18446744073709551615);
	//STR_ShowResult(L"vv Float32", String(-15.26587f).ToFloat32() == -15.26587); // This can't be tested for accuracy :(
	STR_ShowResult(L"vv Float64", String(-15.26535687).ToFloat64() == -15.26535687);
	STR_ShowResult(L"vv Bool", String(true).ToBool() == true);
	STR_CheckStringAndLength(L"Replace", String(L"Hello world!").Replace(String("l"), String("aaa")), L"Heaaaaaao woraaad!", 18);
	STR_CheckStringAndLength(L"Append A", String("Hello") + " " + 69, L"Hello 69", 8);
	wcout << L"##################################################\nFailures: " << failures << endl;
}

int _tmain(int argc, wchar_t* argv[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetBreakAlloc(262);

	STR_Test();
	wcout << endl << endl;

	Test * ptr = new Test();
	Delegate<int> del0 = Delegate<int>::Method(ptr, &Test::OnReceive);
	Delegate<int> del1 = Delegate<int>::Function(&OnReceive);
	Delegate<int> del2(del1);
	del1 = del2;
	del0(NULL, 123456789);
	del1(NULL, 987654321);
	delete ptr;

	wchar_t tmp;
	wcin.get(tmp);
	return 0;
}

