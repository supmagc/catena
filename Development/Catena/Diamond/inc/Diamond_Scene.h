#ifndef _H_DIAMOND_SCENE
#define _H_DIAMOND_SCENE 1

#include "Rock.h"
#include "Chalk.h"
#include "Diamond_Defines.h"

namespace Diamond {

    class Core;
    class Renderer;

    class DIAMOND_API Scene {
    public:
        Scene(Core* pCore, IDevice* pDevice);
        virtual ~Scene();

        Core* GetCore();
        Core const* GetCore() const;
        Renderer* CreateRenderer();
        Array<Renderer*> const& GetRenderers() const;
        void Update(float nDeltaTime, RBOOL bDrawAll = true);

        void Release(Renderer* pRenderer);

    private:
        PIMPL_DECL(Scene);
        CLASS_NOCOPY(Scene);
    };
};

#endif // _H_DIAMOND_SCENE