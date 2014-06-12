
#include "Chalk_D3d9_Std.h"
#include "Chalk_D3d9_SwapChain.h"
#include "Chalk_D3d9_Device.h"


using namespace Rock;
using namespace Chalk;
using namespace Chalk::D3d9;

PIMPL_MAKE(Chalk::D3d9, SwapChain) {
    Device* pDevice;
    IDirect3DSwapChain9* pSwapChain;
    RenderSettings oRenderSettings;
    D3DPRESENT_PARAMETERS oPresentParameters;
};

SwapChain::SwapChain(Device* pDevice) {
    ASSERT_NOTNULL(pDevice);

    PIMPL_INIT(SwapChain);
    PIMPL.pDevice = pDevice;
}

SwapChain::~SwapChain() {
    PIMPL_DELETE();
    SAFE_RELEASE(PIMPL.pSwapChain);
}

RBOOL SwapChain::IsActive() const {
    return RNULL != PIMPL.pSwapChain;
}

RenderSettings const* SwapChain::GetRenderSettings() const {
    return &PIMPL.oRenderSettings;
}

void SwapChain::SetRenderSettings(RenderSettings const* pRenderSettings) {
    ASSERT_NOTNULL(pRenderSettings);
    COPY(pRenderSettings, &PIMPL.oRenderSettings, sizeof(RenderSettings));
}

void SwapChain::Create(CreateSettings const* pCreateSettings, RenderSettings const* pRenderSettings) {
    ASSERT_NOTNULL(pCreateSettings);
    ASSERT_NOTNULL(pRenderSettings);
    ASSERT_TRUE(pCreateSettings->hWindow || pCreateSettings->pSwapChain);
    ASSERT_NULL(PIMPL.pSwapChain);

    SetRenderSettings(pRenderSettings);
    if(pCreateSettings->pSwapChain) {
        PIMPL.pSwapChain = pCreateSettings->pSwapChain;
        CHECK_HRESULT(pCreateSettings->pSwapChain->GetPresentParameters(&PIMPL.oPresentParameters));
    }
    else {
        Convert(pRenderSettings, &PIMPL.oPresentParameters);
        PIMPL.oPresentParameters.hDeviceWindow = pCreateSettings->hWindow;
        CHECK_HRESULT(PIMPL.pDevice->GetDirect3DDevice9()->CreateAdditionalSwapChain(&PIMPL.oPresentParameters, &PIMPL.pSwapChain));
    }
}

void SwapChain::Convert(RenderSettings const* pRenderSettings, D3DPRESENT_PARAMETERS* pPresentParameters) {
    ASSERT_NOTNULL(pRenderSettings);
    ASSERT_NOTNULL(pPresentParameters);

    ZERO(pPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
    pPresentParameters->BackBufferCount = 1;
    pPresentParameters->BackBufferFormat = D3DFMT_A8R8G8B8;
    pPresentParameters->BackBufferWidth = pRenderSettings->nWidth;
    pPresentParameters->BackBufferHeight = pRenderSettings->nHeight;
    pPresentParameters->SwapEffect = D3DSWAPEFFECT_DISCARD;
    pPresentParameters->Windowed = !pRenderSettings->bFullscreen;
}
