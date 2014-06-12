#include "Chalk_d3d9_Std.h"
#include "Chalk_D3d9_Device.h"
#include "Chalk_D3d9_SwapChain.h"


using namespace Chalk;
using namespace Chalk::D3d9;

PIMPL_MAKE(Chalk::D3d9, Device) {
    IDirect3D9* pContext;
    IDirect3DDevice9* pDevice;
};

Device::Device() {
    PIMPL_INIT(Device);
    PIMPL.pContext = Direct3DCreate9(D3D_SDK_VERSION);
}

Device::~Device() {
    SAFE_RELEASE(PIMPL.pDevice);
    SAFE_RELEASE(PIMPL.pContext);
    PIMPL_DELETE();
}

ISwapChain* Device::CreateSwapChain(RCBOX pSettings, RenderSettings const* pRenderSettings) {
    CreateSwapChainSettings const* pSettingsUnboxed = reinterpret_cast<CreateSwapChainSettings const*>(pSettings);
    ASSERT_NOTNULL(pSettingsUnboxed);
    ASSERT_NOTNULL(PIMPL.pContext);
    ASSERT_NOTNULL(pSettingsUnboxed->hWindow);

    SwapChain* pSwapChain = new SwapChain(this);
    SwapChain::CreateSettings oCreateSettings;
    ZERO(&oCreateSettings, sizeof(SwapChain::CreateSettings));
    oCreateSettings.hWindow = pSettingsUnboxed->hWindow;

    if(!PIMPL.pDevice) {
        D3DPRESENT_PARAMETERS oPresentParameters;
        SwapChain::Convert(pRenderSettings, &oPresentParameters);

        CHECK_HRESULT(PIMPL.pContext->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, pSettingsUnboxed->hWindow, D3DCREATE_MIXED_VERTEXPROCESSING, &oPresentParameters, &PIMPL.pDevice));
        CHECK_HRESULT(PIMPL.pDevice->GetSwapChain(0, &oCreateSettings.pSwapChain));
        pSwapChain->Create(&oCreateSettings, pRenderSettings);
    }
    else {
        pSwapChain->Create(&oCreateSettings, pRenderSettings);
    }

    return pSwapChain;
}

void Device::ReleaseSwapChain(ISwapChain* oSwapChain) {
    ASSERT_NOTNULL(oSwapChain);
}

RBOOL Device::BackBufferClear() {
    if(!m_pImpl->pDevice)
        return false;

    m_pImpl->pDevice->Clear(0, RNULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(10, 120, 200), 1, 0);
    m_pImpl->pDevice->BeginScene();
    return true;
}

RBOOL Device::BackBufferSwitch() {
    if(!m_pImpl->pDevice)
        return false;

    m_pImpl->pDevice->EndScene();
    m_pImpl->pDevice->Present(RNULL, RNULL, RNULL, RNULL);
    return true;
}

void Device::Destroy() {
    SAFE_RELEASE(m_pImpl->pDevice);
}

IDirect3D9* Device::GetDirect3D9() {
    return m_pImpl->pContext;
}

IDirect3DDevice9* Device::GetDirect3DDevice9() {
    return m_pImpl->pDevice;
}
