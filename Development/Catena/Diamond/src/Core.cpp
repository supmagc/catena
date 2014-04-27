#include "Diamond_Std.h"
#include "Diamond_Core.h"

using namespace Chalk;
using namespace Diamond;

struct Diamond::Core::CoreImpl {
    IDevice* pDevice;
    IShader* pShader;
    IVertexBuffer *pVertexBuffer;
};

Core::Core() : m_pImpl(RNULL) {
    m_pImpl = new CoreImpl();
}

Core::~Core() {
    SAFE_DELETE(m_pImpl->pVertexBuffer);
    SAFE_DELETE(m_pImpl->pShader);
    SAFE_DELETE(m_pImpl->pDevice);
    SAFE_DELETE(m_pImpl);
}

#ifdef _WINDOWS
RBOOL Core::Create(HWND hWnd) {
    Chalk::D3d9::DeviceSettings oSettings;
    oSettings.hWindow = hWnd;

    m_pImpl->pDevice = new Chalk::D3d9::Device(oSettings);
    if(!m_pImpl->pDevice->Create())
        return false;

    m_pImpl->pShader = new Chalk::D3d9::Shader(dynamic_cast<Chalk::D3d9::Device*>(m_pImpl->pDevice));
    if(!m_pImpl->pShader->Load())
        return false;

    m_pImpl->pVertexBuffer = new Chalk::D3d9::VertexBuffer(dynamic_cast<Chalk::D3d9::Device*>(m_pImpl->pDevice));
    if(!m_pImpl->pVertexBuffer->Load())
        return false;

    return true;
}
#endif

RBOOL Core::Update() {
    RBOOL bError = false;

    if(!m_pImpl->pDevice)
        return false;
    if(!m_pImpl->pShader)
        return false;

    bError = bError || !m_pImpl->pDevice->BackBufferClear();
    bError = bError || !m_pImpl->pShader->Set();

    Matrix mWorld = Matrix();
    Matrix mView = Matrix::CreateViewLH(Vector(0, 0, -10), Vector(0, 0, 0), Vector3(0, 1, 0));
    Matrix mProj = Matrix::CreatePerspectiveLH(60, 1024.0f/768.0f, 0.1f, 100);
    PIMPL.pShader->SetData((mProj * mView).v, 4);

    bError = bError || !m_pImpl->pVertexBuffer->Set();
    bError = bError || !m_pImpl->pDevice->BackBufferSwitch();

    return !bError;
}