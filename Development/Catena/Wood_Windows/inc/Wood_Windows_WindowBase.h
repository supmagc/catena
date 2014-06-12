#ifndef _H_WOOD_WINDOWS_WINDOWBASE
#define _H_WOOD_WINDOWS_WINDOWBASE

#include "Rock.h"
#include "Wood.h"
#include "Wood_Windows_Defines.h"

namespace Wood {

    namespace Windows {

        class WOOD_WINDOWS_API WindowBase : public IWindow {
        public:
            WindowBase(HINSTANCE hInstance);
            virtual ~WindowBase();

            RINT Init(HWND hWindow);
            virtual RINT InitComponents() =0;

            RINT Update();
            virtual RINT UpdateComponents() =0;

            virtual void Show(RINT nShowCmd);
            virtual void Hide();

            HWND GetWindowHandle();
            HINSTANCE GetInstanceHandle();

            static LRESULT CALLBACK WindowProcess(HWND hWnd, UINT eMessage, WPARAM wParam, LPARAM lParam);

        private:
            PIMPL_DECL(WindowBase);
            CLASS_NOCOPY(WindowBase);
        };
    };
};

#endif // _H_WOOD_WINDOWS_WINDOWBASE