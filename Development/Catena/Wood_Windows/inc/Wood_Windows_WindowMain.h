#ifndef _H_WOOD_WINDOWS_WINDOWMAIN
#define _H_WOOD_WINDOWS_WINDOWMAIN

#include "Rock.h"
#include "Wood.h"

namespace Wood {

    namespace Windows {

        struct WindowMainSettings {
            Rock::RUINT nCmdShow;
            Rock::RUINT nIdSplash;
            Rock::RUINT nIdCursor;
            Rock::RUINT nIdNameLong;
            Rock::RUINT nIdNameShort;
            Rock::RUINT nIdIconLarge;
            Rock::RUINT nIdIconSmall;
        };

        class WindowMain : public Wood::WindowMain {
        public:
            WindowMain(HINSTANCE hInstance, WindowMainSettings const& oSettings);
            virtual ~WindowMain();

            virtual Rock::RINT Run();

        private:
            WindowMain(WindowMain const&);
            WindowMain& operator=(WindowMain const&);
        };
    };
};

#endif // _H_WOOD_WINDOWS_WINDOWMAIN