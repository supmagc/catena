#include "Wood_Windows_Std.h"
#include "Wood_Windows_WindowMain.h"

using namespace Rock;
using namespace Diamond;
using namespace Wood::Windows;

Core* g_pCore;
HWND g_hWindow;
HINSTANCE g_hInstance;
WindowMainSettings g_oSettings;
LRESULT CALLBACK Window(HWND hWnd, UINT eMessage, WPARAM wParam, LPARAM lParam);

WindowMain::WindowMain(HINSTANCE hInstance, WindowMainSettings const& oSettings) : Wood::WindowMain() {
    g_hInstance = hInstance;
    g_oSettings = oSettings;
    g_pCore = new Core();
}

WindowMain::~WindowMain() {
    SAFE_DELETE(g_pCore);
}

RINT WindowMain::Run() {
    WNDCLASSEX oClass;
    TCHAR sNameLong[100];
    ATOM nRegisterReturn;
    MSG oMsg;

    LoadString(g_hInstance, g_oSettings.nIdNameLong, sNameLong, 100);

    oClass.cbSize           = sizeof(WNDCLASSEX);
    oClass.style			= CS_HREDRAW | CS_VREDRAW;
    oClass.lpfnWndProc	    = Window;
    oClass.cbClsExtra		= 0;
    oClass.cbWndExtra		= 0;
    oClass.hInstance		= g_hInstance;
    oClass.hIcon			= LoadIcon(g_hInstance, MAKEINTRESOURCE(g_oSettings.nIdIconLarge));
    oClass.hCursor		    = LoadCursor(g_hInstance, MAKEINTRESOURCE(g_oSettings.nIdCursor));
    oClass.hbrBackground	= (HBRUSH)(COLOR_WINDOW+2);
    oClass.lpszMenuName	    = RNULL;
    oClass.lpszClassName	= _T("WoodWindowsWindowMain");
    oClass.hIconSm		    = LoadIcon(g_hInstance, MAKEINTRESOURCE(g_oSettings.nIdIconSmall));

    nRegisterReturn = RegisterClassEx(&oClass);

    g_hWindow = CreateWindow(_T("WoodWindowsWindowMain"), sNameLong, WS_OVERLAPPEDWINDOW, 100, 100, 1024, 768, RNULL, RNULL, g_hInstance, RNULL); 

    ShowWindow(g_hWindow, g_oSettings.nCmdShow);
    UpdateWindow(g_hWindow);
    g_pCore->Create((RINT)g_hWindow);

    while(true) {
        while(PeekMessage(&oMsg, RNULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&oMsg);
            DispatchMessage(&oMsg);
        }

        if(oMsg.message == WM_QUIT)
            break;

        if(!g_pCore->Update())
            break;
    }

    return (int)oMsg.wParam;
}

LRESULT CALLBACK Window(HWND hWnd, UINT eMessage, WPARAM wParam, LPARAM lParam) {
    int eId, eEvent;
    PAINTSTRUCT oPs;
    HDC hDc;

    switch(eMessage)
    {
    case WM_COMMAND:
        eId    = LOWORD(wParam);
        eEvent = HIWORD(wParam);

        /*
        switch (eId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        */
        break;

    case WM_PAINT:
        hDc = BeginPaint(hWnd, &oPs);
        // TODO: Add any drawing code here...
        EndPaint(hWnd, &oPs);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, eMessage, wParam, lParam);
    }

    return 0;
}
