#ifndef _H_CHALK_IDEVICE
#define _H_CHALK_IDEVICE 1

#include "Rock.h"
#include "Chalk_Defines.h"

namespace Chalk {

    class IResource;
    class ISwapChain;
    struct RenderSettings;

    class CHALK_API IDevice {
    public:
        IDevice() {}
        virtual ~IDevice() {}

        virtual ISwapChain* CreateSwapChain(RCBOX pSettings, Chalk::RenderSettings const* oRenderSettings) =0;
        virtual void ActivateSwapChain(ISwapChain* oSwapChain) =0;
        virtual ISwapChain* GetActiveSwapChain() =0;

        virtual void ReleaseResource(IResource* pResource) =0;

        virtual RBOOL Verify() =0;
        virtual RBOOL Clear() =0;
        virtual RBOOL Switch() =0;
        virtual RBOOL Reset() =0;

    private:
        IDevice(IDevice const&);
        IDevice& operator=(IDevice const&);
    };
};

#endif // _H_CHALK_IDEVICE