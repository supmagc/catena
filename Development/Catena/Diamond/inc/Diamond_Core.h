#ifndef _H_DIAMOND_CORE
#define _H_DIAMOND_CORE

#include "Rock.h"
#include "Diamond_Defines.h"

namespace Diamond {

    class Scene;
    class SceneView;

    class DIAMOND_API Core {
    public:
        Core();
        ~Core();

        Scene* GetScene();
        SceneView* CreateSceneView(Rock::RUINT nWidth, Rock::RUINT nHeight);
        void ReleaseSceneView(SceneView* pView);

#ifdef _WINDOWS
#ifndef SWIG
        Rock::RBOOL Create(HWND hWnd, Rock::RUINT nWidth, Rock::RUINT nHeight, Rock::RBOOL bFullscreen);
#endif
        Rock::RBOOL Create(Rock::RINT nWnd, Rock::RUINT nWidth, Rock::RUINT nHeight, Rock::RBOOL bFullscreen);
#endif

        Rock::RBOOL Update();

    private:
        PIMPL_DECL(Core);

        Core(Core const&);
        Core& operator=(Core const&);
    };
};

#endif // _H_DIAMOND_CORE