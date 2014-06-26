#include "Wood_Windows_Std.h"
#include "Wood_Windows_WindowGame.h"

using namespace Wood::Windows;

WindowGame::WindowGame(HINSTANCE hInstance) : WindowBase(hInstance) {
}

WindowGame::~WindowGame() {
}

RINT WindowGame::Init(HCURSOR hCursor, HICON hIconSmall, HICON hIconLarge, WCHAR const* sTitle, RUINT nPosX, RUINT nPosY, RUINT nWidth, RUINT nHeight) {
    CHECK_NULL(GetWindowHandle());

    WNDCLASSEXW oClass;
    ATOM nRegisterReturn;
    HWND hWnd;

    oClass.cbSize           = sizeof(WNDCLASSEXW);
    oClass.style			= CS_HREDRAW | CS_VREDRAW;
    oClass.lpfnWndProc	    = WindowBase::WindowProcess;
    oClass.cbClsExtra		= 0;
    oClass.cbWndExtra		= 0;
    oClass.hInstance		= GetInstanceHandle();
    oClass.hIcon			= hIconSmall;
    oClass.hCursor		    = hCursor;
    oClass.hbrBackground	= (HBRUSH)(COLOR_WINDOW+2);
    oClass.lpszMenuName	    = RNULL;
    oClass.lpszClassName	= RTXT("WoodWindowsWindowMain");
    oClass.hIconSm		    = hIconLarge; // LoadIconW(g_hInstance, MAKEINTRESOURCEW(g_oSettings.nIdIconSmall));

    nRegisterReturn = RegisterClassExW(&oClass);
    hWnd = CreateWindowW(RTXT("WoodWindowsWindowMain"), sTitle, WS_OVERLAPPEDWINDOW, nPosX, nPosY, nWidth, nHeight, RNULL, RNULL, GetInstanceHandle(), this); 
    return Init(hWnd);
}

RINT WindowGame::InitComponents() {
    return 0;
}

RINT WindowGame::UpdateComponents() {
    return 0;
}
