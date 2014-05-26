#ifndef _H_CHALK_D3D9_DEVICE
#define _H_CHALK_D3D9_DEVICE

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

using namespace Rock;

struct IDirect3D9;
struct IDirect3DDevice9;

namespace Chalk {

    namespace D3d9 {

        struct CHALK_D3D9_API DeviceCreateSettings {
            HWND hWindow;
        };

        class CHALK_D3D9_API Device : public Chalk::IDevice {
        public:
            Device();
            virtual ~Device();

            virtual RBOOL Create(RCBOX pSettings, RUINT nWidth, RUINT nHeight, RBOOL bFullscreen);
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