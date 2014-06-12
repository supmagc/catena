#include "Wood_Windows_Std.h"
#include "Wood_Windows_WindowBase.h"

using namespace Wood::Windows;

LRESULT CALLBACK Window(HWND hWnd, UINT eMessage, WPARAM wParam, LPARAM lParam);

PIMPL_MAKE(Wood::Windows, WindowBase) {
    HINSTANCE hInstance;
    HWND hWindow;
};

WindowBase::WindowBase(HINSTANCE hInstance) {
    PIMPL_INIT(WindowBase);
}

WindowBase::~WindowBase() {
    PIMPL_DELETE();
}

RINT WindowBase::Init(HWND hWnd) {
    PIMPL.hWindow = hWnd;

    return 0 == (RINT)hWnd ? 1 : 0;
}

RINT WindowBase::Update() {
    ASSERT_NOTNULL(PIMPL.hWindow);

    if(UpdateWindow(PIMPL.hWindow)) {
        UpdateComponents();
        return 0;
    }
    return 1;
}

void WindowBase::Show(RINT nShowCmd) {
    ASSERT_NOTNULL(PIMPL.hWindow);

    ShowWindow(PIMPL.hWindow, nShowCmd);
}

void WindowBase::Hide() {
    ASSERT_NOTNULL(PIMPL.hWindow);

    ShowWindow(PIMPL.hWindow, SW_HIDE);
}

HWND WindowBase::GetWindowHandle() {
    return PIMPL.hWindow;
}

HINSTANCE WindowBase::GetInstanceHandle() {
    return PIMPL.hInstance;
}

LRESULT CALLBACK WindowBase::WindowProcess(HWND hWnd, UINT eMessage, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT oPs;
    HDC hDc;
    WindowBase* pWindow;

    if(eMessage == WM_INITDIALOG) {
        pWindow = reinterpret_cast<WindowBase*>(lParam);
        SetWindowLongPtr(hWnd, DWLP_USER, reinterpret_cast<LONG_PTR>(pWindow));
    }
    else {
        pWindow = reinterpret_cast<WindowBase*>(GetWindowLongPtr(hWnd, DWLP_USER));
    }

    switch(eMessage)
    {
    case WM_PAINT:
        hDc = BeginPaint(hWnd, &oPs);
        // TODO: Add any drawing code here...
        EndPaint(hWnd, &oPs);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProcW(hWnd, eMessage, wParam, lParam);
    }

    return 0;
}
