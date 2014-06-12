#ifndef _H_DIAMOND_SCENEVIEW
#define _H_DIAMOND_SCENEVIEW 1

#include "Rock.h"
#include "Chalk.h"
#include "Diamond_Defines.h"

namespace Diamond {

    class Scene;

    class DIAMOND_API SceneView {
    public:
#ifndef _SWIG
        SceneView(ISwapChain* pSwapChain);
#endif
        ~SceneView();

        void SetSize(RUINT nWidth, RUINT nHeight);
        void SetFullscreen(RBOOL bFullscreen);
        RUINT GetWidth() const;
        RUINT GetHeight() const;
        RBOOL GetFullscreen() const;

#ifndef _SWIG
        ISwapChain* GetSwapChain();
        ISwapChain const* GetSwapChain() const;
#endif

    private:
        PIMPL_DECL(SceneView);
        CLASS_NOCOPY(SceneView);
    };
};

#endif // _H_DIAMOND_SCENEVIEW