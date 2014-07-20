#ifndef _H_WOOD_WINDOWS_WINDOWGAME
#define _H_WOOD_WINDOWS_WINDOWGAME

#include "Wood_Windows_Defines.h"
#include "Wood_Windows_WindowBase.h"

#include "Rock.h"
#include "Wood.h"
#include "Diamond.h"

namespace Wood {

    namespace Windows {

        class WOOD_WINDOWS_API WindowGame : public WindowBase {
        public:
            WindowGame(HINSTANCE hInstance, Core* pCore);
            virtual ~WindowGame();

            using WindowBase::Init;
            RINT Init(HCURSOR hCursor, HICON hIconSmall, HICON hIconLarge, WCHAR const* sTitle, RUINT nPosX, RUINT nPosY, RUINT nWidth, RUINT nHeight);

            virtual RINT InitComponents();
            virtual RINT UpdateComponents();

        private:
            PIMPL_DECL(WindowGame);
            CLASS_NOCOPY(WindowGame);
        };
    };
};

#endif // _H_WOOD_WINDOWS_WINDOWGAME