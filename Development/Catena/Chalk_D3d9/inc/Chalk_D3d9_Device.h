#ifndef _H_CHALK_D3D9_DEVICE
#define _H_CHALK_D3D9_DEVICE

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

namespace Chalk {

    namespace D3d9 {

        class CHALK_D3D9_API Device : public Chalk::IDevice {
        public:
            Device();
            virtual ~Device();

            virtual ISwapChain* CreateSwapChain(HWND hWnd, Chalk::RenderSettings const* oRenderSettings);
            virtual void ActivateSwapChain(ISwapChain* oSwapChain);
            virtual ISwapChain* GetActiveSwapChain();

            virtual void ReleaseResource(IResource* pResource);

            virtual RBOOL Verify();
            virtual RBOOL Clear();
            virtual RBOOL Switch();
            virtual RBOOL Reset();

            IDirect3D9* GetDirect3D9();
            IDirect3DDevice9* GetDirect3DDevice9();

        private:
            struct DeviceImpl;
            DeviceImpl* m_pImpl;

            Device(Device const&);
            Device& operator=(Device const&);
        };
    };
};

#endif // _H_CHALK_D3D9_DEVICE