#include "Chalk_D3d9_Std.h"
#include "Chalk_D3d9_Shader.h"
#include "Chalk_D3d9_Device.h"

#include <d3d9.h>
#include <d3dcompiler.h>

using namespace Chalk::D3d9;

struct Chalk::D3d9::Shader::ShaderImpl {
    IDirect3DDevice9* pDevice;
    ID3DBlob* pDataPS;
    ID3DBlob* pDataVS;
    IDirect3DPixelShader9* pPS;
    IDirect3DVertexShader9* pVS;
};

Shader::Shader(Device* pDevice) : m_pImpl(RNULL), Chalk::Shader() {
    m_pImpl = new ShaderImpl();
    ZeroMemory(m_pImpl, sizeof(ShaderImpl));

    m_pImpl->pDevice = pDevice->GetDirect3DDevice9();
}

Shader::~Shader() {
    SAFE_RELEASE(m_pImpl->pDataPS);
    SAFE_RELEASE(m_pImpl->pDataVS);
    SAFE_DELETE(m_pImpl);
}

RBOOL Shader::Load() {
    if(!m_pImpl->pDevice)
        return false;

    RUINT nFlags = D3DCOMPILE_DEBUG;
    auto sFilePS = String(L"..\\..\\Catena\\Resources\\PixelShader.hlsl");
    auto sFileVS = String(L"..\\..\\Catena\\Resources\\VertexShader.hlsl");
    ID3DBlob* pErrorPS = RNULL;
    ID3DBlob* pErrorVS = RNULL;

    HRESULT hResultCompilePS = D3DCompileFromFile(sFilePS.GetData(), RNULL, RNULL, "main", "ps_2_0", nFlags, 0, &m_pImpl->pDataPS, &pErrorPS);
    HRESULT hResultCompileVS = D3DCompileFromFile(sFileVS.GetData(), RNULL, RNULL, "main", "vs_2_0", nFlags, 0, &m_pImpl->pDataVS, &pErrorVS);

    if(FAILED(hResultCompilePS) || FAILED(hResultCompileVS)) {
        OutputDebugStringA((char*)pErrorPS->GetBufferPointer());
        OutputDebugStringA((char*)pErrorVS->GetBufferPointer());
        SAFE_RELEASE(m_pImpl->pDataPS);
        SAFE_RELEASE(m_pImpl->pDataVS);
        return false;
    }

    HRESULT hResultPS = m_pImpl->pDevice->CreatePixelShader((DWORD*)m_pImpl->pDataPS->GetBufferPointer(), &m_pImpl->pPS);
    HRESULT hResultVS = m_pImpl->pDevice->CreateVertexShader((DWORD*)m_pImpl->pDataVS->GetBufferPointer(), &m_pImpl->pVS);

    if(FAILED(hResultPS) || FAILED(hResultVS)) {
        SAFE_RELEASE(m_pImpl->pDataPS);
        SAFE_RELEASE(m_pImpl->pDataVS);
        SAFE_RELEASE(m_pImpl->pPS);
        SAFE_RELEASE(m_pImpl->pVS);
        return false;
    }

    return true;
}

RBOOL Shader::Set() {
    if(!m_pImpl->pDevice)
        return false;
    if(!m_pImpl->pDataPS)
        return false;
    if(!m_pImpl->pDataVS)
        return false;

    HRESULT hResultPS = m_pImpl->pDevice->SetPixelShader(m_pImpl->pPS);
    HRESULT hResultVS = m_pImpl->pDevice->SetVertexShader(m_pImpl->pVS);
    return !FAILED(hResultPS) && !FAILED(hResultVS);
}