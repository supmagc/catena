#ifndef _H_DIAMOND_CORE
#define _H_DIAMOND_CORE 1

#include "Diamond_Defines.h"

#include "Rock.h"

namespace Diamond {

    class Scene;
    class WindowCanvas;
    class InteractiveViewer;

    class DIAMOND_API Core {
    public:
        Core();
        virtual ~Core();

        Scene* CreateScene();
        WindowCanvas* CreateWindowCanvas();
        InteractiveViewer* CreateInteractiveViewer();

        Array<Scene*> const& GetScenes() const;

        RBOOL Update();

        void Release(Scene* pScene);
        void Release(WindowCanvas* pCanvas);
        void Release(InteractiveViewer* pViewer);

    private:
        PIMPL_DECL(Core);
        CLASS_NOCOPY(Core);
    };
};

#endif // _H_DIAMOND_CORE