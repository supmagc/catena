#include "Catena_Std.h"
#include "Resources.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR pCmdLine, int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(pCmdLine);

    Wood::WindowMain* pWindowMain = RNULL;
    Rock::RINT nReturn = 0;

#ifdef _WINDOWS
#ifdef _DEBUG
    _CrtCheckMemory();
    _CrtDumpMemoryLeaks();
    //_CrtSetBreakAlloc();
#endif

    Wood::Windows::WindowMainSettings oSettings;
    oSettings.nCmdShow = nCmdShow;
    oSettings.nIdCursor = IDC_CURSOR;
    oSettings.nIdSplash = IDB_SPLASH;
    oSettings.nIdIconLarge = IDI_ICON_LARGE;
    oSettings.nIdIconSmall = IDI_ICON_SMALL;
    oSettings.nIdNameShort = IDS_NAME_SHORT;
    oSettings.nIdNameLong = IDS_NAME_LONG;
    pWindowMain = new Wood::Windows::WindowMain(hInstance, oSettings);
#endif

    nReturn = pWindowMain->Run();
    SAFE_DELETE(pWindowMain);
    return nReturn;
}
