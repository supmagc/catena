
#include "Chalk_D3d9_Std.h"
#include "Chalk_D3d9_SwapChain.h"
#include "Chalk_D3d9_Device.h"

#include <d3d9.h>

using namespace Rock;
using namespace Chalk::D3d9;

PIMPL_MAKE(Chalk::D3d9, SwapChain) {
    Device* pDevice;
    IDirect3DSwapChain9* pSwapChain;
};

SwapChain::SwapChain(Device* pDevice, IDirect3DSwapChain9* pSwapChain) {
    PIMPL_INIT(SwapChain);
    PIMPL.pDevice = pDevice;
    PIMPL.pSwapChain = pSwapChain;

    ASSERT_NOTNULL(pDevice);
}

SwapChain::~SwapChain() {
    PIMPL_DELETE();
}

RBOOL SwapChain::IsActive() const {
    return RNULL != PIMPL.pSwapChain;
}

RBOOL SwapChain::Create(HWND hWnd, RUINT nWidth, RUINT nHeight, RBOOL bFullscreen) {
    ASSERT_NULL(PIMPL.pSwapChain);

    D3DPRESENT_PARAMETERS oParameters;
    ZeroMemory(&oParameters, sizeof(D3DPRESENT_PARAMETERS));
    oParameters.hDeviceWindow = hWnd;
    oParameters.BackBufferCount = 1;
    oParameters.BackBufferFormat = D3DFMT_A8R8G8B8;
    oParameters.BackBufferWidth = nWidth;
    oParameters.BackBufferHeight = nHeight;
    oParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
    oParameters.Windowed = !bFullscreen;

    PIMPL.pDevice->GetDirect3DDevice9()->CreateAdditionalSwapChain(&oParameters, &PIMPL.pSwapChain);
}