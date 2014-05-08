#include "Chalk_D3d9_std.h"
#include "Chalk_D3d9_IndexBuffer.h"
#include "Chalk_D3d9_Device.h"

#include <d3d9.h>

using namespace Chalk::D3d9;

PIMPL_MAKE(Chalk::D3d9, IndexBuffer) {
    Device* pDevice;
    IDirect3DIndexBuffer9* pIndexBuffer;
};

IndexBuffer::IndexBuffer(Device* pDevice) {
    PIMPL_INIT(IndexBuffer);
    PIMPL.pDevice = pDevice;
}

IndexBuffer::~IndexBuffer() {
    PIMPL_DELETE();
}

RBOOL IndexBuffer::Load() {
    return true;
}

RBOOL IndexBuffer::Set() {
    return true;
}