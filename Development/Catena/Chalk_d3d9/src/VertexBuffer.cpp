#include "Chalk_D3d9_Std.h"
#include "Chalk_D3d9_VertexBuffer.h"
#include "Chalk_D3d9_Device.h"

#include <d3d9.h>

using namespace Chalk::D3d9;

PIMPL_MAKE(Chalk::D3d9, VertexBuffer) {
    Device* pDevice;
    IDirect3DVertexBuffer9 *pVertexBuffer;
};

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
struct CUSTOMVERTEX {
    RFLOAT x, y, z, rhw;
    DWORD color;
};

VertexBuffer::VertexBuffer(Device* pDevice) {
    PIMPL_INIT(VertexBuffer);
    PIMPL.pDevice = pDevice;
}

VertexBuffer::~VertexBuffer() {
    SAFE_RELEASE(m_pImpl->pVertexBuffer);
    PIMPL_DELETE();
}

RBOOL VertexBuffer::Load() {
    void* pData = RNULL;
    CUSTOMVERTEX aVertices[] = {
        {320.0f, 50.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 0, 255)},
        {520.0f, 400.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 255, 0)},
        {120.0f, 400.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(255, 0, 0)},
    };

    m_pImpl->pDevice->GetDirect3DDevice9()->CreateVertexBuffer(3*sizeof(CUSTOMVERTEX), 0, CUSTOMFVF, D3DPOOL_MANAGED, &m_pImpl->pVertexBuffer, RNULL);
    m_pImpl->pVertexBuffer->Lock(0, 3*sizeof(CUSTOMVERTEX), &pData, 0);
    memcpy_s(pData, sizeof(aVertices), &aVertices, sizeof(aVertices));
    m_pImpl->pVertexBuffer->Unlock();

    return true;
}

RBOOL VertexBuffer::Set() {
    m_pImpl->pDevice->GetDirect3DDevice9()->SetFVF(CUSTOMFVF);
    m_pImpl->pDevice->GetDirect3DDevice9()->SetStreamSource(0, m_pImpl->pVertexBuffer, 0, sizeof(CUSTOMVERTEX));
    m_pImpl->pDevice->GetDirect3DDevice9()->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

    return true;
}