
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
    CHECK_NOTNULL(pDevice);
    CHECK_NOTNULL(pDevice->GetDirect3DDevice9());

    PIMPL_INIT(SwapChain);
    PIMPL.pDevice = pDevice;
}

SwapChain::~SwapChain() {
    PIMPL_DELETE();
    SAFE_RELEASE(PIMPL.pSwapChain);
}

void SwapChain::Init(InitSettings const* pInitSettings, RenderSettings const* pRenderSettings) {
    CHECK_NOTNULL(pInitSettings);
    CHECK_NOTNULL(pRenderSettings);
    CHECK_TRUE(pInitSettings->hWindow || pInitSettings->pSwapChain);
    CHECK_NULL(PIMPL.pSwapChain);

    SetRenderSettings(pRenderSettings);
    if(pInitSettings->pSwapChain) {
        PIMPL.pSwapChain = pInitSettings->pSwapChain;
        CHECK_HRESULT(pInitSettings->pSwapChain->GetPresentParameters(&PIMPL.oPresentParameters));
    }
    else {
        Convert(pRenderSettings, &PIMPL.oPresentParameters);
        PIMPL.oPresentParameters.hDeviceWindow = pInitSettings->hWindow;
        CHECK_HRESULT(PIMPL.pDevice->GetDirect3DDevice9()->CreateAdditionalSwapChain(&PIMPL.oPresentParameters, &PIMPL.pSwapChain));
    }
}

void SwapChain::Activate() {
    return PIMPL.pDevice->ActivateSwapChain(this);
}

RBOOL SwapChain::IsActive() const {
    return PIMPL.pDevice->GetActiveSwapChain() == this;
}

RBOOL SwapChain::HasResource() const {
    return RNULL != PIMPL.pSwapChain;
}

RenderSettings const* SwapChain::GetRenderSettings() const {
    return &PIMPL.oRenderSettings;
}

void SwapChain::SetRenderSettings(RenderSettings const* pRenderSettings) {
    CHECK_NOTNULL(pRenderSettings);
    COPY(pRenderSettings, &PIMPL.oRenderSettings, sizeof(RenderSettings));
}

IDirect3DSwapChain9* SwapChain::GetDirect3DSwapChain() {
    return PIMPL.pSwapChain;
}

IDirect3DSurface9* SwapChain::GetDirect3DSurface() {
    CHECK_NOTNULL(PIMPL.pSwapChain);
    IDirect3DSurface9* pSurface;
    CHECK_HRESULT(PIMPL.pSwapChain->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &pSurface));
    return pSurface;
}

D3DPRESENT_PARAMETERS const* SwapChain::GetDirect3DPresentParameters() {
    return &PIMPL.oPresentParameters;
}

void SwapChain::Convert(RenderSettings const* pRenderSettings, D3DPRESENT_PARAMETERS* pPresentParameters) {
    CHECK_NOTNULL(pRenderSettings);
    CHECK_NOTNULL(pPresentParameters);

    ZERO(pPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
    pPresentParameters->BackBufferCount = 1;
    pPresentParameters->BackBufferFormat = D3DFMT_A8R8G8B8;
    pPresentParameters->BackBufferWidth = pRenderSettings->nWidth;
    pPresentParameters->BackBufferHeight = pRenderSettings->nHeight;
    pPresentParameters->SwapEffect = D3DSWAPEFFECT_DISCARD;
    pPresentParameters->Windowed = !pRenderSettings->bFullscreen;
}
