#ifndef _H_WOOD_IMAINLOOP
#define _H_WOOD_IMAINLOOP

#include "Rock.h"
#include "Wood_Defines.h"

namespace Wood {

    class WOOD_API IMainLoop {
    public:
        IMainLoop() {}
        virtual ~IMainLoop() {}

        virtual RINT Init(RCBOX pSettings) =0;
        virtual RINT Run(RCBOX pSettings) =0;

    private:
        CLASS_NOCOPY(IMainLoop);
    };
};

#endif // _H_WOOD_IMAINLOOP