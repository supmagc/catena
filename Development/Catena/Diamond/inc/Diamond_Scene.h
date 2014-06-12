#ifndef _H_DIAMOND_SCENE
#define _H_DIAMOND_SCENE 1

#include "Rock.h"
#include "Diamond_Defines.h"

namespace Diamond {

    class SceneView;

    class DIAMOND_API Scene {
    public:
        Scene();
        ~Scene();

    private:
        PIMPL_DECL(Scene);
        CLASS_NOCOPY(Scene);
    };
};

#endif // _H_DIAMOND_SCENE