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

RINT MainLoop::Init(RCBOX pInitSettings) {
    UNBOX(InitSettings, pSettings);

    PIMPL.pWindowGame = new WindowGame(pSettings->hInstance);
    PIMPL.pWindowGameTest = new WindowGame(pSettings->hInstance);

    HICON hIconSmall = LoadIconW(pSettings->hInstance, MAKEINTRESOURCEW(pSettings->nIdIconSmall));
    HICON hIconLarge = LoadIconW(pSettings->hInstance, MAKEINTRESOURCEW(pSettings->nIdIconLarge));
    HCURSOR hCursor = LoadCursorW(pSettings->hInstance, MAKEINTRESOURCEW(pSettings->nIdCursor));

    PIMPL.pWindowGame->Init(hCursor, hIconSmall, hIconLarge, RTXT("TEST"), 100, 100, 1024, 768);
    PIMPL.pCore->Create((RINT)PIMPL.pWindowGame->GetWindowHandle(), 1024, 768, false);
    PIMPL.pWindowGame->Show(pSettings->nCmdShow);
    PIMPL.pWindowGame->Update();

    PIMPL.pWindowGameTest->Init(hCursor, hIconSmall, hIconLarge, RTXT("TEST"), 100, 100, 1024, 768);
    PIMPL.pCore->Create((RINT)PIMPL.pWindowGameTest->GetWindowHandle(), 1024, 768, false);
    PIMPL.pWindowGameTest->Show(pSettings->nCmdShow);
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
