#ifndef _H_CHALK_IDEVICE
#define _H_CHALK_IDEVICE

#include "Rock.h"
#include "Chalk_Defines.h"

namespace Chalk {

    class ISwapChain;
    struct RenderSettings;

    class CHALK_API IDevice {
    public:
        IDevice() {}
        virtual ~IDevice() {}

        virtual ISwapChain* CreateSwapChain(RCBOX pSettings, Chalk::RenderSettings const* oRenderSettings) =0;
        virtual void ReleaseSwapChain(ISwapChain* oSwapChain) =0;

        virtual RBOOL BackBufferClear() =0;
        virtual RBOOL BackBufferSwitch() =0;
        virtual void Destroy() =0;

    private:
        IDevice(IDevice const&);
        IDevice& operator=(IDevice const&);
    };
};

#endif // _H_CHALK_IDEVICE