#ifndef _H_WOOD_WINDOWS_MAINLOOP
#define _H_WOOD_WINDOWS_MAINLOOP

#include "Rock.h"
#include "Wood.h"
#include "Wood_Windows_Defines.h"

namespace Wood {

    namespace Windows {

        class WOOD_WINDOWS_API MainLoop : public IMainLoop {
        public:
            struct WOOD_WINDOWS_API InitSettings {
                HINSTANCE hInstance;
                RUINT nCmdShow;
                RUINT nIdSplash;
                RUINT nIdCursor;
                RUINT nIdNameLong;
                RUINT nIdNameShort;
                RUINT nIdIconLarge;
                RUINT nIdIconSmall;
            };

            struct WOOD_WINDOWS_API RunSettings {

            };

            MainLoop();
            virtual ~MainLoop();

            virtual RINT Init(RCBOX pSettings);
            virtual RINT Run(RCBOX pSettings);

        private:
            PIMPL_DECL(MainLoop);
            CLASS_NOCOPY(MainLoop);
        };
    };
};

#endif // _H_WOOD_WINDOWS_MAINLOOP