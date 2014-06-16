#ifndef _H_CHALK_IRESOURCE
#define _H_CHALK_IRESOURCE 1

#include "Chalk_Defines.h"

namespace Chalk {

    class IDevice;

    class CHALK_API IResource {
    public:
        IResource() {}

        virtual void Release() =0;
        virtual IDevice* GetDevice() =0;
        virtual void OnDeviceLost() =0;
        virtual void OnDeviceReset() =0;
        
    protected:
        virtual ~IResource() {}

    private:
        CLASS_NOCOPY(IResource);
    };
};

#endif // _H_CHALK_IRESOURCE