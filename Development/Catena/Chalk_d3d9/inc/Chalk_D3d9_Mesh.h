#ifndef _H_CHALK_D3D9_MESH
#define _H_CHALK_D3D9_MESH

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

using namespace Rock;

namespace Chalk {

    namespace D3d9 {

        class CHALK_D3D9_API Mesh : public Chalk::Mesh {
        public:
            Mesh();
            virtual ~Mesh();

        private:
            Mesh(Mesh const&);
            Mesh& operator=(Mesh const&);
        };
    };
};

#endif // _H_CHALK_D3D9_MESH