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
        SceneView* CreateSceneView(RUINT nWidth, RUINT nHeight);
        void ReleaseSceneView(SceneView* pView);

        SceneView* Create(RINT nWnd, RUINT nWidth, RUINT nHeight, RBOOL bFullscreen);

        RBOOL Update();

    private:
        PIMPL_DECL(Core);

        Core(Core const&);
        Core& operator=(Core const&);
    };
};

#endif // _H_DIAMOND_CORE