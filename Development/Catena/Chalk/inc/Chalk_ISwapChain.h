#ifndef _H_CHALK_ISWAPCHAIN
#define _H_CHALK_ISWAPCHAIN 1

#include "Chalk_Defines.h"

namespace Chalk {

    class CHALK_API ISwapChain {
    public:
        ISwapChain() {}
        virtual ~ISwapChain() {}

    private:
        CLASS_NOCOPY(ISwapChain);
    };
};

#endif // _H_CHALK_ISWAPCHAIN