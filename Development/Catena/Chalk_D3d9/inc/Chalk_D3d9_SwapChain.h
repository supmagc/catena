#ifndef _H_CHALK_D3D9_SWAPCHAIN
#define _H_CHALK_D3D9_SWAPCHAIN 1

#include "Rock.h"
#include "Chalk_D3d9_Defines.h"

namespace Chalk {

    struct RenderSettings;

    namespace D3d9 {

        class Device;

        class CHALK_D3D9_API SwapChain : public ISwapChain {
        public:
            struct CHALK_D3D9_API CreateSettings {
                HWND hWindow;
                IDirect3DSwapChain9* pSwapChain;
            };

            SwapChain(Device* pDevice);
            virtual ~SwapChain();

            virtual RBOOL IsActive() const;
            virtual RenderSettings const* GetRenderSettings() const;
            virtual void SetRenderSettings(RenderSettings const* pRenderSettings);

            void Create(CreateSettings const* pCreateSettings, RenderSettings const* pRenderSettings);

            static void Convert(RenderSettings const* pRenderSettings, D3DPRESENT_PARAMETERS* pPresentParameters);

        private:
            PIMPL_DECL(SwapChain);
            CLASS_NOCOPY(SwapChain);
        };
    };
};

#endif // _H_CHALK_D3D9_SWAPCHAIN