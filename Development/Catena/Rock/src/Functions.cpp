
#include "Rock_Std.h"
#include "Rock_Functions.h"

using namespace Rock;

ROCK_API void catBreakPoint() {
    BREAK_ALWAYS;
}

ROCK_API void catOutputLog(String const& sLog) {
    OutputDebugStringW(*sLog);
}

ROCK_API RBOOL catIsDebug() {
#if defined(_DEBUG)
    return true;
#else
    return false;
#endif
}

ROCK_API RBOOL catIsRelease() {
#if !defined(_DEBUG) && !defined(_PUBLISH)
    return true;
#else
    return false;
#endif
}

ROCK_API RBOOL catIsPublish() {
#if defined(_PUBLISH)
    return true;
#else
    return false;
#endif
}

ROCK_API String catWorkingDirectory() {
    RINT nSize = GetCurrentDirectoryW(0, RNULL);
    RCHAR* aWorkingDirectory = (RCHAR*)malloc(RCHAR_SIZE * nSize);
    GetCurrentDirectoryW(nSize, aWorkingDirectory);
    SAFE_DELETE_ARRAY(aWorkingDirectory);
    return String(aWorkingDirectory);
}

ROCK_API String catCommandLine() {
    return String(GetCommandLineW());
}

ROCK_API void catMessageBoxInfo(String const& sTitle, String const& sMessage) {
    MessageBoxW(RNULL, *sMessage, *sTitle, MB_ICONINFORMATION | MB_OK);
}

ROCK_API void catMessageBoxWarning(String const& sTitle, String const& sMessage) {
    MessageBoxW(RNULL, *sMessage, *sTitle, MB_ICONEXCLAMATION | MB_OK);
}

ROCK_API void catMessageBoxAlert(String const& sTitle, String const& sMessage) {
    MessageBoxW(RNULL, *sMessage, *sTitle, MB_ICONERROR | MB_OK);
}

ROCK_API RBOOL catMessageBoxConfirm(String const& sTitle, String const& sMessage) {
    return MessageBoxW(RNULL, *sMessage, *sTitle, MB_ICONINFORMATION | MB_OKCANCEL) == IDOK;
}

ROCK_API void catPostQuitMessage(RINT nCode) {
    PostQuitMessage(nCode);
}

ROCK_API void catSleep(RDOUBLE nDuration) {
    Sleep((RINT64)(nDuration * 1000.0));
}