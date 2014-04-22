#include "Chalk_d3d9_Std.h"
#include "Chalk_D3d9_Device.h"

#include <d3d9.h>

using namespace Chalk::D3d9;

struct Chalk::D3d9::Device::DeviceImpl {
    IDirect3D9* pContext;
    IDirect3DDevice9* pDevice;
};

Device::Device(DeviceSettings const& oSettings) : m_pImpl(RNULL), m_oSettings(oSettings), Chalk::Device() {
    m_pImpl = new DeviceImpl();
    m_pImpl->pContext = Direct3DCreate9(D3D_SDK_VERSION);
}

Device::~Device() {
    SAFE_RELEASE(m_pImpl->pDevice);
    SAFE_RELEASE(m_pImpl->pContext);
    SAFE_DELETE(m_pImpl);
}

RBOOL Device::Create() {
    if(!m_pImpl->pContext)
        return false;
    if(!m_oSettings.hWindow)
        return false;
    if(m_pImpl->pDevice)
        return false;

    D3DPRESENT_PARAMETERS oParameters;
    ZeroMemory(&oParameters, sizeof(D3DPRESENT_PARAMETERS));
    oParameters.BackBufferCount = 1;
    oParameters.BackBufferFormat = D3DFMT_A8R8G8B8;
    oParameters.BackBufferWidth = 1024;
    oParameters.BackBufferHeight = 768;
    oParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
    oParameters.Windowed = true;

    if(D3D_OK == m_pImpl->pContext->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_oSettings.hWindow, D3DCREATE_MIXED_VERTEXPROCESSING, &oParameters, &m_pImpl->pDevice)) {
        return true;
    }
    else {
        m_pImpl->pDevice = RNULL;
        return false;
    }
}

RBOOL Device::BackBufferClear() {
    if(!m_pImpl->pDevice)
        return false;

    m_pImpl->pDevice->Clear(0, RNULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 100, 160), 1, 0);
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
