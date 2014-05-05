#ifndef _H_DIAMOND_CORE
#define _H_DIAMOND_CORE

#include "Rock.h"
#include "Diamond_Defines.h"

namespace Diamond {

    class DIAMOND_API Core {
    public:
        Core();
        ~Core();

#ifdef _WINDOWS
#ifndef SWIG
        Rock::RBOOL Create(HWND hWnd);
#endif
        Rock::RBOOL Create(Rock::RINT nWnd);
#endif

        Rock::RBOOL Update();

    private:
        struct CoreImpl;
        CoreImpl* m_pImpl;

        Core(Core const&);
        Core& operator=(Core const&);
    };
};

#endif // _H_DIAMOND_CORE