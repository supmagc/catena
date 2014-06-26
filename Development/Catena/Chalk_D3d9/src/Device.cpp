#include "Chalk_d3d9_Std.h"
#include "Chalk_D3d9_Device.h"
#include "Chalk_D3d9_SwapChain.h"
#include "Chalk_D3d9_Resource.h"

using namespace Chalk;
using namespace Chalk::D3d9;

PIMPL_MAKE(Chalk::D3d9, Device) {
    IDirect3D9* pContext;
    IDirect3DDevice9* pDevice;
    SwapChain* pActiveSwapChain;

    Array<Resource*> lResources;
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

ISwapChain* Device::CreateSwapChain(SETTINGS_PARAM(CreateSwapChain), RenderSettings const* pRenderSettings) {
    SETTINGS_UNBOX(CreateSwapChain);
    CHECK_NOTNULL(PIMPL.pContext);
    CHECK_NOTNULL(pCreateSwapChainSettings->hWindow);

    SwapChain* pSwapChain = new SwapChain(this);
    SETTINGS_INIT(Chalk::D3d9::SwapChain, Init);
    SETTINGS(Init).hWindow = pCreateSwapChainSettings->hWindow;

    if(!PIMPL.pDevice) {
        D3DPRESENT_PARAMETERS oPresentParameters;
        SwapChain::Convert(pRenderSettings, &oPresentParameters);

        CHECK_HRESULT(PIMPL.pContext->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, pCreateSwapChainSettings->hWindow, D3DCREATE_MIXED_VERTEXPROCESSING, &oPresentParameters, &PIMPL.pDevice));
        CHECK_HRESULT(PIMPL.pDevice->GetSwapChain(0, &SETTINGS(Init).pSwapChain));
        pSwapChain->Init(&SETTINGS(Init), pRenderSettings);
        PIMPL.pActiveSwapChain = pSwapChain;
    }
    else {
        pSwapChain->Init(&SETTINGS(Init), pRenderSettings);
    }

    return pSwapChain;
}

void Device::ActivateSwapChain(ISwapChain* pSwapChain) {
    PIMPL.pActiveSwapChain = dynamic_cast<SwapChain*>(pSwapChain);
}

ISwapChain* Device::GetActiveSwapChain() {
    return PIMPL.pActiveSwapChain;
}

void Device::ReleaseResource(IResource* pResource) {
    CHECK_NOTNULL(pResource);
}

RBOOL Device::Verify() {
    CHECK_NOTNULL(PIMPL.pDevice);

    HRESULT nCooperativeLevel = PIMPL.pDevice->TestCooperativeLevel();

    if(SUCCEEDED(nCooperativeLevel)) {
        return true;
    }
    else {
        if(nCooperativeLevel == D3DERR_DEVICEHUNG) {

        }
        if(nCooperativeLevel == D3DERR_DEVICELOST) {
            catSleep(1);
        }
        if(nCooperativeLevel == D3DERR_DEVICENOTRESET) {
            // OnLostDevice
            //PIMPL.pDevice->Reset(PIMPL.pActiveSwapChain->GetDirect3DSurface
            //CHECK_HRESULT
            // OnDeviceReset
        }
        if(nCooperativeLevel == D3DERR_DEVICEREMOVED) {

        }
        if(nCooperativeLevel == D3DERR_DRIVERINTERNALERROR) {

        }
        if(nCooperativeLevel == D3DERR_DRIVERINVALIDCALL) {

        }
        switch(nCooperativeLevel) {

        }
        return false;
    }
}

RBOOL Device::Clear() {
    if(!m_pImpl->pDevice)
        return false;

    CHECK_HRESULT(PIMPL.pDevice->SetRenderTarget(0, PIMPL.pActiveSwapChain->GetDirect3DSurface()));
    CHECK_HRESULT(PIMPL.pDevice->Clear(0, RNULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(10, 120, 200), 1, 0));
    CHECK_HRESULT(PIMPL.pDevice->BeginScene());
    return true;
}

RBOOL Device::Switch() {
    if(!m_pImpl->pDevice)
        return false;

    CHECK_HRESULT(PIMPL.pDevice->EndScene());
    CHECK_HRESULT(PIMPL.pActiveSwapChain->GetDirect3DSwapChain()->Present(RNULL, RNULL, RNULL, RNULL, 0));
    return true;
}

IDirect3D9* Device::GetDirect3D9() {
    return m_pImpl->pContext;
}

IDirect3DDevice9* Device::GetDirect3DDevice9() {
    return m_pImpl->pDevice;
}
