
#include "Rock_Std.h"
#include "Rock_Checks.h"
#include "Rock_Functions.h"
#include "Rock_Console.h"

using namespace Rock;

Console::Console() : m_hConsole(INVALID_HANDLE_VALUE) {
	AllocConsole();
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CHECK_FALSE(m_hConsole == INVALID_HANDLE_VALUE);
}

Console::~Console() {
	if(GetStdHandle(STD_OUTPUT_HANDLE) == m_hConsole)
		fclose(stdout);

	m_hConsole = INVALID_HANDLE_VALUE;
	FreeConsole();
}

void Console::AttachToStdOut() {
	FILE* pStream;
	freopen_s(&pStream, "CONOUT$", "w", stdout);
}

void Console::Write(String const& sData) {
	DWORD nWritten;
	WriteConsole(m_hConsole, *sData, sData.GetLength(), &nWritten, RNULL);
}
