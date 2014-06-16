#include "Wood_Windows_Std.h"
#include "Wood_Windows_MainLoop.h"
#include "Wood_Windows_WindowGame.h"

using namespace Wood::Windows;


PIMPL_MAKE(Wood::Windows, MainLoop) {
    Core* pCore;
    WindowGame* pWindowGame;
    WindowGame* pWindowGameTest;
};

MainLoop::MainLoop() {
    PIMPL_INIT(MainLoop);

    PIMPL.pCore = new Core();
}

MainLoop::~MainLoop() {
    PIMPL_DELETE();
}

RINT MainLoop::Init(SETTINGS_PARAM(Init)) {
    SETTINGS_UNBOX(Init);

    PIMPL.pWindowGame = new WindowGame(pInitSettings->hInstance);
    PIMPL.pWindowGameTest = new WindowGame(pInitSettings->hInstance);

    RCHAR sName[100];
    HICON hIconSmall = LoadIconW(pInitSettings->hInstance, MAKEINTRESOURCEW(pInitSettings->nIdIconSmall));
    HICON hIconLarge = LoadIconW(pInitSettings->hInstance, MAKEINTRESOURCEW(pInitSettings->nIdIconLarge));
    HCURSOR hCursor = LoadCursorW(pInitSettings->hInstance, MAKEINTRESOURCEW(pInitSettings->nIdCursor));
    LoadStringW(pInitSettings->hInstance, pInitSettings->nIdNameLong, sName, 99);

    PIMPL.pWindowGame->Init(hCursor, hIconSmall, hIconLarge, sName, 100, 100, 1024, 768);
    PIMPL.pCore->Create((RINT)PIMPL.pWindowGame->GetWindowHandle(), 1024, 768, false);
    PIMPL.pWindowGame->Show(pInitSettings->nCmdShow);
    PIMPL.pWindowGame->Update();

    PIMPL.pWindowGameTest->Init(hCursor, hIconSmall, hIconLarge, sName, 200, 200, 1024, 768);
    PIMPL.pCore->Create((RINT)PIMPL.pWindowGameTest->GetWindowHandle(), 1024, 768, false);
    PIMPL.pWindowGameTest->Show(pInitSettings->nCmdShow);
    PIMPL.pWindowGameTest->Update();

    return 0;
}

RINT MainLoop::Run(RCBOX pRunSettings) {
    MSG oMsg;

    while(true) {
        while(PeekMessageW(&oMsg, RNULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&oMsg);
            DispatchMessageW(&oMsg);
        }

        if(oMsg.message == WM_QUIT)
            break;

        if(!PIMPL.pCore->Update())
            break;
    }

    return (int)oMsg.wParam;

    return 0;
}
