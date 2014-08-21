
#include "Rock_Std.h"
#include "Rock_Checks.h"
#include "Rock_Functions.h"
#include "Rock_Console.h"

using namespace Rock;

HANDLE Console::s_hConsole = INVALID_HANDLE_VALUE;
RUINT32 Console::s_nInstanceCount = 0;

Console::Console() {
	if(s_nInstanceCount == 0) {
		CHECK_RESULT_TRUE(AllocConsole());
		s_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CHECK_NOTEQUAL(s_hConsole, INVALID_HANDLE_VALUE);
	}
	++s_nInstanceCount;
}

Console::~Console() {
	fclose(stdout);
	--s_nInstanceCount;
	if(s_nInstanceCount == 0) {
		s_hConsole = INVALID_HANDLE_VALUE;
		FreeConsole();
	}
}

void Console::AttachToStdOut() {
	FILE* pStream;
	freopen_s(&pStream, "CONOUT$", "w", stdout);
}

void Console::SetColor(Color eForegroundColor, RBOOL bForegroundIntens, Color eBackgroundColor, RBOOL bBackgroundIntens) {
	WORD nColor = 0;
	nColor |= (RBYTE)eForegroundColor;
	nColor |= (RBYTE)eBackgroundColor << 4;
	if(bForegroundIntens)
		nColor |= 0x08;
	if(bBackgroundIntens)
		nColor |= 0x08;
	SetConsoleTextAttribute(s_hConsole, nColor);
}

void Console::Write(String const& sData) {
	DWORD nWritten;
	WriteConsole(s_hConsole, *sData, sData.GetLength(), &nWritten, RNULL);
}
