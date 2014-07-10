#ifndef _H_CHALK_ISWAPCHAIN
#define _H_CHALK_ISWAPCHAIN 1

#include "Rock.h"
#include "Chalk_Defines.h"
#include "Chalk_IResource.h"

namespace Chalk {

    struct RenderSettings;

    class CHALK_API ISwapChain : public IResource{
    public:
        ISwapChain() {}

        virtual void Activate() =0;
        virtual RBOOL IsActive() const =0;
        virtual RBOOL HasResource() const =0;
        virtual RenderSettings const* GetRenderSettings() const =0;
        virtual void SetRenderSettings(RenderSettings const* pRenderSettings) =0;

    protected:
        virtual ~ISwapChain() {}

    private:
        CLASS_NOCOPY(ISwapChain);
    };
};

#endif // _H_CHALK_ISWAPCHAIN