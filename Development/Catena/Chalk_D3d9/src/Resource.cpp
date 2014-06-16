#include "Chalk_D3d9_Std.h"
#include "Chalk_D3d9_Resource.h"
#include "Chalk_D3d9_Device.h"

using namespace Chalk::D3d9;

Resource::Resource(Device* pDevice) : pDevice(pDevice) {
    ASSERT_NOTNULL(pDevice);
}

Resource::~Resource() {
    pDevice = RNULL;
}

void Resource::Release() {
    if(RNULL != pDevice) {
        Device* pTemp = pDevice;
        pDevice = RNULL;
        pTemp->ReleaseResource(this);
        delete this;
    }
}

Device* Resource::GetDevice() {
    return pDevice;
}

void Resource::OnDeviceLost() {
    // Empty stub, implementation in derived classes
}

void Resource::OnDeviceReset() {
    // Empty stub, implementation in derived classes
}
