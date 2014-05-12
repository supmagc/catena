#ifndef _H_WOOD_WINDOWMAIN
#define _H_WOOD_WINDOWMAIN

#include "Rock.h"
#include "Wood_Defines.h"

namespace Wood {

    class WOOD_API WindowMain {
    public:
        WindowMain();
        virtual ~WindowMain();

        virtual Rock::RINT Run() = 0;

    private:
        WindowMain(WindowMain const&);
        WindowMain& operator=(WindowMain const&);
    };
};

#endif // _H_WOOD_WINDOWMAIN