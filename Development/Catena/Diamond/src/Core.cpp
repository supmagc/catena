#include "Diamond_Std.h"
#include "Diamond_Core.h"

using namespace Chalk;
using namespace Diamond;

struct Diamond::Core::CoreImpl {
    Device* pDevice;
};

Core::Core() : m_pImpl(RNULL) {
    m_pImpl = new CoreImpl();
}

Core::~Core() {
    SAFE_DELETE(m_pImpl->pDevice);
    SAFE_DELETE(m_pImpl);
}

#ifdef _WINDOWS
RBOOL Core::Create(HWND hWnd) {
    Chalk::D3d9::DeviceSettings oSettings;
    oSettings.hWindow = hWnd;
    m_pImpl->pDevice = new Chalk::D3d9::Device(oSettings);
    return m_pImpl->pDevice->CreateDevice();
}
#endif

RBOOL Core::Update() {
    if(!m_pImpl->pDevice)
        return false;

    return m_pImpl->pDevice->BackBufferClear() && m_pImpl->pDevice->BackBufferSwitch();
}