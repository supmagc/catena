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
            SETTINGS_DECL(Init, CHALK_D3D9_API) {
                HWND hWindow;
                IDirect3DSwapChain9* pSwapChain;
            };

            SwapChain(Device* pDevice);
            virtual ~SwapChain();

            virtual void Activate();
            virtual RBOOL IsActive() const;
            virtual RBOOL HasResource() const;
            virtual RenderSettings const* GetRenderSettings() const;
            virtual void SetRenderSettings(RenderSettings const* pRenderSettings);

            void Init(InitSettings const* pInitSettings, RenderSettings const* pRenderSettings);
            IDirect3DSwapChain9* GetDirect3DSwapChain();
            IDirect3DSurface9* GetDirect3DSurface();
            D3DPRESENT_PARAMETERS const* GetDirect3DPresentParameters();

            static void Convert(RenderSettings const* pRenderSettings, D3DPRESENT_PARAMETERS* pPresentParameters);

        private:
            PIMPL_DECL(SwapChain);
            CLASS_NOCOPY(SwapChain);
        };
    };
};

#endif // _H_CHALK_D3D9_SWAPCHAIN