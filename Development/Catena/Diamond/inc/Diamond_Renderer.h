#ifndef _H_DIAMOND_RENDERER
#define _H_DIAMOND_RENDERER 1

#include "Diamond_Defines.h"
#include "Chalk.h"

namespace Diamond {

    class Scene;
    class ICanvas;
    class IViewer;

    class DIAMOND_API Renderer {
    public:
        Renderer(Scene* pScene, IDevice* pDevice);
        virtual ~Renderer();

        void Draw();
        void SetCanvas(ICanvas* pCanvas);
        void SetViewer(IViewer* pViewer);
        ICanvas* GetCanvas();
        ICanvas const* GetCanvas() const;
        IViewer* GetViewer();
        IViewer const* GetViewer() const;
        Scene* GetScene();
        Scene const* GetScene() const;

    private:
        PIMPL_DECL(Renderer);
        CLASS_NOCOPY(Renderer);
    };
};

#endif // _H_DIAMOND_RENDERER