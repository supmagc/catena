#ifndef _H_DIAMOND_MESH
#define _H_DIAMOND_MESH 1

#include "Diamond_Defines.h"

#include "Chalk.h"

namespace Diamond {

    class Core;

    class DIAMOND_API Mesh {
    public:
        Mesh(Core* pCore, IDevice* pDevice);
        virtual ~Mesh();

        void Draw();

    private:
        PIMPL_DECL(Mesh);
        CLASS_NOCOPY(Mesh);
    };
};

#endif // _H_DIAMOND_MESH