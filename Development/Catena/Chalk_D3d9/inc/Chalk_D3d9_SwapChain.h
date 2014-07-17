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
            SwapChain(Device* pDevice);

            virtual void Release();
            virtual IDevice* GetDevice();
            virtual IDevice const* GetDevice() const;
            virtual void OnDeviceLost();
            virtual void OnDeviceReset();

            virtual void Activate();
            virtual RBOOL IsActive() const;
            virtual RBOOL HasResource() const;
            virtual RenderSettings const* GetRenderSettings() const;
            virtual void SetRenderSettings(RenderSettings const* pRenderSettings);

            void Init(HWND hWnd, RenderSettings const* pRenderSettings);
            void Init(IDirect3DSwapChain9* pSwapChain, RenderSettings const* pRenderSettings);

            IDirect3DSwapChain9* GetDirect3DSwapChain();
            IDirect3DSurface9* GetDirect3DSurface();
            D3DPRESENT_PARAMETERS* GetDirect3DPresentParameters();

            static void Convert(RenderSettings const* pRenderSettings, D3DPRESENT_PARAMETERS* pPresentParameters);

        protected:
            virtual ~SwapChain();

        private:
            PIMPL_DECL(SwapChain);
            CLASS_NOCOPY(SwapChain);
        };
    };
};

#endif // _H_CHALK_D3D9_SWAPCHAIN