#ifndef _H_WOOD_WINDOWMAIN
#define _H_WOOD_WINDOWMAIN

#include "Wood_Std.h"

using namespace Rock;

namespace Wood {

    class WindowMain {
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