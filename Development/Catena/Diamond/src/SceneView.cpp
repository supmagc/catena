#include "Diamond_Std.h"
#include "Diamond_SceneView.h"

using namespace Diamond;

PIMPL_MAKE(Diamond, SceneView) {
    ISwapChain* pSwapChain;
};

SceneView::SceneView(ISwapChain* pSwapChain) {
    CHECK_NOTNULL(pSwapChain);

    PIMPL_INIT(SceneView);
    PIMPL.pSwapChain = pSwapChain;
}

SceneView::~SceneView() {
    PIMPL_DELETE();
}

void SceneView::SetSize(RUINT nWidth, RUINT nHeight) {
    RenderSettings oRenderSettings;
    COPY(PIMPL.pSwapChain->GetRenderSettings(), &oRenderSettings, sizeof(RenderSettings));
    oRenderSettings.nWidth = nWidth;
    oRenderSettings.nHeight = nHeight;
    PIMPL.pSwapChain->SetRenderSettings(&oRenderSettings);
}

void SceneView::SetFullscreen(RBOOL bFullscreen) {
    RenderSettings oRenderSettings;
    COPY(PIMPL.pSwapChain->GetRenderSettings(), &oRenderSettings, sizeof(RenderSettings));
    oRenderSettings.bFullscreen = bFullscreen;
    PIMPL.pSwapChain->SetRenderSettings(&oRenderSettings);
}

RUINT SceneView::GetWidth() const {
    return PIMPL.pSwapChain->GetRenderSettings()->nWidth;
}

RUINT SceneView::GetHeight() const {
    return PIMPL.pSwapChain->GetRenderSettings()->nHeight;
}

RBOOL SceneView::GetFullscreen() const {
    return PIMPL.pSwapChain->GetRenderSettings()->bFullscreen;
}

Chalk::ISwapChain* SceneView::GetSwapChain() {
    return PIMPL.pSwapChain;
}

Chalk::ISwapChain const* SceneView::GetSwapChain() const {
    return PIMPL.pSwapChain;
}
