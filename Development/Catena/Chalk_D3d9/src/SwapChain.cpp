
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

    PIMPL_INIT(SwapChain);
    PIMPL.pDevice = pDevice;
}

SwapChain::~SwapChain() {
    SAFE_RELEASE(PIMPL.pSwapChain);
    PIMPL_DELETE();
}

void SwapChain::Release() {
    CHECK_NOTNULL(PIMPL.pDevice);
    PIMPL.pDevice->ReleaseResource(this);
    delete this;
}

IDevice* SwapChain::GetDevice() {
    return PIMPL.pDevice;
}

IDevice const* SwapChain::GetDevice() const {
    return PIMPL.pDevice;
}

void SwapChain::OnDeviceLost() {
    SAFE_RELEASE(PIMPL.pSwapChain);
}

void SwapChain::OnDeviceReset() {

}

void SwapChain::Init(HWND hWnd, RenderSettings const* pRenderSettings) {
    CHECK_NULL(PIMPL.pSwapChain);
    CHECK_NOTNULL(pRenderSettings);
    CHECK_NOTNULL(hWnd);

    SetRenderSettings(pRenderSettings);
    Convert(pRenderSettings, &PIMPL.oPresentParameters);
    PIMPL.oPresentParameters.hDeviceWindow = hWnd;
    CHECK_HRESULT(PIMPL.pDevice->GetDirect3DDevice9()->CreateAdditionalSwapChain(&PIMPL.oPresentParameters, &PIMPL.pSwapChain));
}

void SwapChain::Init(IDirect3DSwapChain9* pSwapChainNative, RenderSettings const* pRenderSettings) {
    CHECK_NULL(PIMPL.pSwapChain);
    CHECK_NOTNULL(pRenderSettings);
    CHECK_NOTNULL(pSwapChainNative);

    SetRenderSettings(pRenderSettings);
    Convert(pRenderSettings, &PIMPL.oPresentParameters);
    PIMPL.pSwapChain = pSwapChainNative;
    CHECK_HRESULT(pSwapChainNative->GetPresentParameters(&PIMPL.oPresentParameters));
}
//
//void SwapChain::Activate() {
//    return PIMPL.pDevice->ActivateSwapChain(this);
//}
//
//RBOOL SwapChain::IsActive() const {
//    return PIMPL.pDevice->GetActiveSwapChain() == this;
//}
//
//RBOOL SwapChain::HasResource() const {
//    return RNULL != PIMPL.pSwapChain;
//}

RenderSettings const* SwapChain::GetRenderSettings() const {
    return &PIMPL.oRenderSettings;
}

void SwapChain::SetRenderSettings(RenderSettings const* pRenderSettings) {
    CHECK_NOTNULL(pRenderSettings);
    catMemCopy(pRenderSettings, &PIMPL.oRenderSettings, sizeof(RenderSettings));
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

D3DPRESENT_PARAMETERS* SwapChain::GetDirect3DPresentParameters() {
    return &PIMPL.oPresentParameters;
}

void SwapChain::Convert(RenderSettings const* pRenderSettings, D3DPRESENT_PARAMETERS* pPresentParameters) {
    CHECK_NOTNULL(pRenderSettings);
    CHECK_NOTNULL(pPresentParameters);

    catMemZero(pPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
    pPresentParameters->BackBufferCount = 1;
    pPresentParameters->BackBufferFormat = D3DFMT_A8R8G8B8;
    pPresentParameters->BackBufferWidth = pRenderSettings->nWidth;
    pPresentParameters->BackBufferHeight = pRenderSettings->nHeight;
    pPresentParameters->SwapEffect = D3DSWAPEFFECT_DISCARD;
    pPresentParameters->Windowed = !pRenderSettings->bFullscreen;
}
