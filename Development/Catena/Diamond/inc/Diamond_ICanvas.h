#ifndef _H_DIAMOND_ICANVAS
#define _H_DIAMOND_ICANVAS 1

#include "Diamond_Defines.h"

namespace Diamond {

    class DIAMOND_API ICanvas {
    public:
        virtual void Activate() = 0;
    };
};

#endif // _H_DIAMOND_ICANVAS