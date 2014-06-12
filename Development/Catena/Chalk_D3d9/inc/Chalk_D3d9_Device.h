#ifndef _H_CHALK_D3D9_DEVICE
#define _H_CHALK_D3D9_DEVICE

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

namespace Chalk {

    namespace D3d9 {

        class CHALK_D3D9_API Device : public Chalk::IDevice {
        public:
            struct CHALK_D3D9_API CreateSwapChainSettings {
                HWND hWindow;
            };

            Device();
            virtual ~Device();

            virtual ISwapChain* CreateSwapChain(RCBOX pSettings, Chalk::RenderSettings const* oRenderSettings);
            virtual void ReleaseSwapChain(ISwapChain* oSwapChain);

            virtual RBOOL BackBufferClear();
            virtual RBOOL BackBufferSwitch();
            virtual void Destroy();

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