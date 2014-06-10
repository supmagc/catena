#ifndef _H_CHALK_IDEVICE
#define _H_CHALK_IDEVICE

#include "Rock.h"
#include "Chalk_Defines.h"

using namespace Rock;

namespace Chalk {

    class CHALK_API IDevice {
    public:
        IDevice() {}
        virtual ~IDevice() {}

        virtual RBOOL Create(RCBOX pSettings, Chalk::RenderSettings const& oRenderSettings) =0;
        virtual RBOOL BackBufferClear() =0;
        virtual RBOOL BackBufferSwitch() =0;
        virtual void Destroy() =0;

    private:
        IDevice(IDevice const&);
        IDevice& operator=(IDevice const&);
    };
};

#endif // _H_CHALK_IDEVICE