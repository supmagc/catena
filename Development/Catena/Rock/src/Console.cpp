
#include "Rock_Std.h"
#include "Rock_Checks.h"
#include "Rock_Functions.h"
#include "Rock_Console.h"

using namespace Rock;

Console Console::s_oSingleton;

Console::Console() : m_hConsole(INVALID_HANDLE_VALUE) {
}

Console::~Console() {
    Hide();
}

void Console::Show() {
    if(s_oSingleton.m_hConsole == INVALID_HANDLE_VALUE) {
        CHECK_RESULT_TRUE(AllocConsole());
        s_oSingleton.m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CHECK_NOTEQUAL(s_oSingleton.m_hConsole, INVALID_HANDLE_VALUE);

        // Reattack std-out, this assures that although we didn't have a
        // console at the program startup, the std-out is send to the console
        FILE* pStream;
        freopen_s(&pStream, "CONOUT$", "w", stdout);
    }
}

void Console::Hide() {
    if(s_oSingleton.m_hConsole != INVALID_HANDLE_VALUE) {
        // Make sure we don't reset the std-out when is has been redirected
        if(GetStdHandle(STD_OUTPUT_HANDLE) == s_oSingleton.m_hConsole)
            fclose(stdout);

        s_oSingleton.m_hConsole = INVALID_HANDLE_VALUE;
        FreeConsole();
    }
}

void Console::SetColor(Color eForegroundColor, RBOOL bForegroundIntens, Color eBackgroundColor, RBOOL bBackgroundIntens) {
    WORD nColor = 0;
    nColor |= (RBYTE)eForegroundColor;
    nColor |= (RBYTE)eBackgroundColor << 4;
    if(bForegroundIntens)
        nColor |= 0x08;
    if(bBackgroundIntens)
        nColor |= 0x08;
    SetConsoleTextAttribute(s_oSingleton.m_hConsole, nColor);
}
