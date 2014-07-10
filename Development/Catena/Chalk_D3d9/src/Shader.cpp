#include "Chalk_D3d9_Std.h"
#include "Chalk_D3d9_Shader.h"
#include "Chalk_D3d9_Device.h"

#include <d3d9.h>
#include <d3dcompiler.h>

using namespace Chalk::D3d9;

PIMPL_MAKE(Chalk::D3d9, Shader) {
    Device* pDevice;
    ID3DBlob* pDataPS;
    ID3DBlob* pDataVS;
    IDirect3DPixelShader9* pPS;
    IDirect3DVertexShader9* pVS;
};

Shader::Shader(Device* pDevice) {
    PIMPL_INIT(Shader);

    m_pImpl->pDevice = pDevice;
}

Shader::~Shader() {
    SAFE_RELEASE(m_pImpl->pDataPS);
    SAFE_RELEASE(m_pImpl->pDataVS);
    PIMPL_DELETE();
}

void Shader::Release() {
    CHECK_NOTNULL(PIMPL.pDevice);
    PIMPL.pDevice->ReleaseResource(this);
    delete this;
}

IDevice* Shader::GetDevice() {
    return PIMPL.pDevice;
}

IDevice const* Shader::GetDevice() const {
    return PIMPL.pDevice;
}

void Shader::OnDeviceLost() {
}

void Shader::OnDeviceReset() {
}

RBOOL Shader::Load() {
    if(!m_pImpl->pDevice)
        return false;

    RUINT nFlags = D3DCOMPILE_DEBUG;
    auto sFilePS = String(L"PixelShader.hlsl");
    auto sFileVS = String(L"VertexShader.hlsl");
    ID3DBlob* pErrorPS = RNULL;
    ID3DBlob* pErrorVS = RNULL;

    HRESULT hResultCompilePS = D3DCompileFromFile(sFilePS.GetData(), RNULL, RNULL, "main", "ps_2_0", nFlags, 0, &m_pImpl->pDataPS, &pErrorPS);
    HRESULT hResultCompileVS = D3DCompileFromFile(sFileVS.GetData(), RNULL, RNULL, "main", "vs_2_0", nFlags, 0, &m_pImpl->pDataVS, &pErrorVS);

    if(FAILED(hResultCompilePS) || FAILED(hResultCompileVS)) {
        OutputDebugStringA((char*)pErrorPS->GetBufferPointer());
        OutputDebugStringA((char*)pErrorVS->GetBufferPointer());
        SAFE_RELEASE(PIMPL.pDataPS);
        SAFE_RELEASE(PIMPL.pDataVS);
        return false;
    }

    HRESULT hResultPS = PIMPL.pDevice->GetDirect3DDevice9()->CreatePixelShader((DWORD*)m_pImpl->pDataPS->GetBufferPointer(), &m_pImpl->pPS);
    HRESULT hResultVS = PIMPL.pDevice->GetDirect3DDevice9()->CreateVertexShader((DWORD*)m_pImpl->pDataVS->GetBufferPointer(), &m_pImpl->pVS);

    if(FAILED(hResultPS) || FAILED(hResultVS)) {
        SAFE_RELEASE(PIMPL.pDataPS);
        SAFE_RELEASE(PIMPL.pDataVS);
        SAFE_RELEASE(PIMPL.pPS);
        SAFE_RELEASE(PIMPL.pVS);
        return false;
    }

    return true;
}

RBOOL Shader::Set() {
    if(!PIMPL.pDevice)
        return false;
    if(!PIMPL.pDataPS)
        return false;
    if(!PIMPL.pDataVS)
        return false;

    HRESULT hResultPS = PIMPL.pDevice->GetDirect3DDevice9()->SetPixelShader(PIMPL.pPS);
    HRESULT hResultVS = PIMPL.pDevice->GetDirect3DDevice9()->SetVertexShader(PIMPL.pVS);

    PIMPL.pDevice->GetDirect3DDevice9()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    return !FAILED(hResultPS) && !FAILED(hResultVS);
}

void Shader::SetData(RINT const* aData, RUINT nLength) {
    PIMPL.pDevice->GetDirect3DDevice9()->SetVertexShaderConstantI(0, aData, nLength);
}

void Shader::SetData(RFLOAT const* aData, RUINT nLength) {
    PIMPL.pDevice->GetDirect3DDevice9()->SetVertexShaderConstantF(0, aData, nLength);
}
