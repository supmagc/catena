#include "Chalk_D3d9_Std.h"
#include "Chalk_D3d9_VertexBuffer.h"
#include "Chalk_D3d9_Device.h"

#include <d3d9.h>

using namespace Chalk::D3d9;

PIMPL_MAKE(Chalk::D3d9, VertexBuffer) {
    Device* pDevice;
    IDirect3DVertexBuffer9 *pVertexBuffer;
    IDirect3DVertexDeclaration9 *pVertexDeclaration;
};

struct CUSTOMVERTEX {
    Vector3 vPos;
    D3DCOLOR oCol;
};

VertexBuffer::VertexBuffer(Device* pDevice) {
    PIMPL_INIT(VertexBuffer);
    PIMPL.pDevice = pDevice;
}

VertexBuffer::~VertexBuffer() {
    SAFE_RELEASE(PIMPL.pVertexDeclaration);
    SAFE_RELEASE(PIMPL.pVertexBuffer);
    PIMPL_DELETE();
}

void VertexBuffer::Release() {
    CHECK_NOTNULL(PIMPL.pDevice);
    PIMPL.pDevice->ReleaseResource(this);
    delete this;
}

IDevice* VertexBuffer::GetDevice() {
    return PIMPL.pDevice;
}

IDevice const* VertexBuffer::GetDevice() const {
    return PIMPL.pDevice;
}

void VertexBuffer::OnDeviceLost() {}

void VertexBuffer::OnDeviceReset() {}

RBOOL VertexBuffer::Load() {
    void* pData = RNULL;
    CUSTOMVERTEX aVertices[] = {
        {Vector3(-1, 0, 0), D3DCOLOR_XRGB(0, 0, 255)},
        {Vector3(0, 1, 0), D3DCOLOR_XRGB(0, 255, 0)},
        {Vector3(1, -1, 0), D3DCOLOR_XRGB(255, 0, 0)},
    };

    D3DVERTEXELEMENT9 aDeclaration[] = {
        {0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
        {0, sizeof(Vector3), D3DDECLTYPE_D3DCOLOR, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0},
        D3DDECL_END()
    };

    HRESULT hDeclaration = PIMPL.pDevice->GetDirect3DDevice9()->CreateVertexDeclaration(aDeclaration, &PIMPL.pVertexDeclaration);
    HRESULT hBuffer = PIMPL.pDevice->GetDirect3DDevice9()->CreateVertexBuffer(3*sizeof(CUSTOMVERTEX), 0, 0, D3DPOOL_MANAGED, &PIMPL.pVertexBuffer, RNULL);

    if(FAILED(hDeclaration) || FAILED(hBuffer)) {
        SAFE_RELEASE(PIMPL.pVertexDeclaration);
        SAFE_RELEASE(PIMPL.pVertexBuffer);
        return false;
    }
    else {
        PIMPL.pVertexBuffer->Lock(0, sizeof(aVertices), &pData, 0);
        memcpy_s(pData, sizeof(aVertices), &aVertices, sizeof(aVertices));
        PIMPL.pVertexBuffer->Unlock();
    }

    return true;
}

RBOOL VertexBuffer::Set() {
    PIMPL.pDevice->GetDirect3DDevice9()->SetVertexDeclaration(PIMPL.pVertexDeclaration);
    PIMPL.pDevice->GetDirect3DDevice9()->SetStreamSource(0, PIMPL.pVertexBuffer, 0, sizeof(CUSTOMVERTEX));
    PIMPL.pDevice->GetDirect3DDevice9()->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

    return true;
}