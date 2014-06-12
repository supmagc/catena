#ifndef _H_WOOD_IWINDOW
#define _H_WOOD_IWINDOW

#include "Rock.h"
#include "Wood_Defines.h"

namespace Wood {

    class WOOD_API IWindow {
    public:
        IWindow() {}
        virtual ~IWindow() {}

    private:
        CLASS_NOCOPY(IWindow);
    };
};

#endif // _H_WOOD_IWINDOW