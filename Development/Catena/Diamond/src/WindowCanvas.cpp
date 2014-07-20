
#include "Diamond_Std.h"
#include "Diamond_WindowCanvas.h"
#include "Diamond_Core.h"

using namespace Diamond;

PIMPL_MAKE(Diamond, WindowCanvas) {
    Core* pCore;
    IDevice* pDevice;
    ISwapChain* pSwapChain;
};

WindowCanvas::WindowCanvas(Core* pCore, IDevice* pDevice) {
    PIMPL_INIT(WindowCanvas);
    CHECK_NOTNULL(pCore);
    CHECK_NOTNULL(pDevice);
    PIMPL.pCore = pCore;
    PIMPL.pDevice = pDevice;
}

WindowCanvas::~WindowCanvas() {
    if(RNULL != PIMPL.pSwapChain)
        PIMPL.pDevice->ReleaseResource(PIMPL.pSwapChain);

    PIMPL_DELETE();
}

Core* WindowCanvas::GetCore() {
    return PIMPL.pCore;
}

Core const* WindowCanvas::GetCore() const {
    return PIMPL.pCore;
}

void WindowCanvas::Init(RINT hWnd, RUINT nWidth, RUINT nHeight, RBOOL bFullscreen) {
    CHECK_NULL(PIMPL.pSwapChain);

    Chalk::RenderSettings oRenderSettings;
    oRenderSettings.nWidth = nWidth;
    oRenderSettings.nHeight = nHeight;
    oRenderSettings.bFullscreen = bFullscreen;

    PIMPL.pSwapChain = PIMPL.pDevice->CreateSwapChain((HWND)hWnd, &oRenderSettings);
    CHECK_NOTNULL(PIMPL.pSwapChain);
}

void WindowCanvas::Activate() {
    CHECK_NOTNULL(PIMPL.pDevice);
    CHECK_NOTNULL(PIMPL.pSwapChain);
    PIMPL.pDevice->ActivateSwapChain(PIMPL.pSwapChain);
}

