#include "Launcher_Std.h"
#include "Resources.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR pCmdLine, int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(pCmdLine);

    IMainLoop* pMainLoop = RNULL;
    RINT nReturn = 0;

#ifdef _WINDOWS
#ifdef _DEBUG
    //_CrtCheckMemory();
    //_CrtDumpMemoryLeaks();
    //_CrtSetBreakAlloc();
#endif

    Wood::Windows::MainLoop::InitSettings oSettings;
    oSettings.hInstance = hInstance;
    oSettings.nCmdShow = nCmdShow;
    oSettings.nIdCursor = IDC_CURSOR;
    oSettings.nIdSplash = IDB_SPLASH;
    oSettings.nIdIconLarge = IDI_ICON_LARGE;
    oSettings.nIdIconSmall = IDI_ICON_SMALL;
    oSettings.nIdNameShort = IDS_NAME_SHORT;
    oSettings.nIdNameLong = IDS_NAME_LONG;
    pMainLoop = new MainLoop();
    pMainLoop->Init(&oSettings);
#endif

    nReturn = pMainLoop->Run(RNULL);
    SAFE_DELETE(pMainLoop);
    return nReturn;
}
