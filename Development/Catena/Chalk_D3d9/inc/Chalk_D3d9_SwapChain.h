#ifndef _H_CHALK_D3D9_SWAPCHAIN
#define _H_CHALK_D3D9_SWAPCHAIN 1

#include "Rock.h"
#include "Chalk_D3d9_Defines.h"

class IDirect3DSwapChain9;

namespace Chalk {

    namespace D3d9 {

        class CHALK_D3D9_API SwapChain {
        public:
            SwapChain(Device* pDevice, IDirect3DSwapChain9* pSwapChain);
            virtual ~SwapChain();

            Rock::RBOOL IsActive() const;
            Rock::RBOOL Create(HWND hWnd, Rock::RUINT nWidth, Rock::RUINT nHeight, Rock::RBOOL bFullscreen);

        private:
            PIMPL_DECL(SwapChain);
            CLASS_NOCOPY(SwapChain);
        };
    };
};

#endif // _H_CHALK_D3D9_SWAPCHAIN