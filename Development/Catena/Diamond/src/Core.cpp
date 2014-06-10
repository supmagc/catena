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
#ifndef SWIG
RBOOL Core::Create(HWND hWnd, RUINT nWidth, RUINT nHeight, RBOOL bFullscreen) {
    Chalk::D3d9::DeviceCreateSettings oSettings;
    oSettings.hWindow = hWnd;

    m_pImpl->pDevice = new Chalk::D3d9::Device();
    if(!m_pImpl->pDevice->Create(&oSettings, nWidth, nHeight, bFullscreen))
        return false;

    m_pImpl->pShader = new Chalk::D3d9::Shader(dynamic_cast<Chalk::D3d9::Device*>(m_pImpl->pDevice));
    if(!m_pImpl->pShader->Load())
        return false;

    m_pImpl->pVertexBuffer = new Chalk::D3d9::VertexBuffer(dynamic_cast<Chalk::D3d9::Device*>(m_pImpl->pDevice));
    if(!m_pImpl->pVertexBuffer->Load())
        return false;

    return true;
}
#endif // SWIG

RBOOL Core::Create(RINT nWnd, RUINT nWidth, RUINT nHeight, RBOOL bFullscreen) {
    return Create((HWND)nWnd, nWidth, nHeight, bFullscreen);
}
#endif // _WINDOWS

RFLOAT g_nDir = 1;
RFLOAT g_nTemp = 0;

RBOOL Core::Update() {
    RBOOL bError = false;

    ASSERT(m_pImpl->pDevice != RNULL);
    ASSERT(m_pImpl->pShader != RNULL);

    bError = bError || !m_pImpl->pDevice->BackBufferClear();
    bError = bError || !m_pImpl->pShader->Set();

    Matrix mWorld = Matrix();
    g_nTemp += g_nDir * 0.01f;
    if(g_nTemp > 5) {g_nTemp = 5; g_nDir =-1;}
    if(g_nTemp <-5) {g_nTemp =-5; g_nDir = 1;}
    Matrix mView = Matrix::CreateViewLH(Vector(g_nTemp, 0, -2), Vector(0, 0, 0), Vector3(0, 1, 0));
    Matrix mProj = Matrix::CreatePerspectiveLH(45, 1024.0f/768.0f, 0.1f, 100);
    Matrix mWVP = mView * mProj;
    PIMPL.pShader->SetData(mWVP.v, 4);

    bError = bError || !m_pImpl->pVertexBuffer->Set();
    bError = bError || !m_pImpl->pDevice->BackBufferSwitch();

    return !bError;
}