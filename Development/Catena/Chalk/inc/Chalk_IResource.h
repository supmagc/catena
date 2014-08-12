#ifndef _H_CHALK_IRESOURCE
#define _H_CHALK_IRESOURCE 1

#include "Chalk_Defines.h"

namespace Chalk {

    class IDevice;

    class CHALK_API IResource {
    public:
        virtual void Release() =0;
        virtual IDevice* GetDevice() =0;
        virtual IDevice const* GetDevice() const =0;
        virtual void OnDeviceLost() =0;
        virtual void OnDeviceReset() =0;
    };
};

#endif // _H_CHALK_IRESOURCE