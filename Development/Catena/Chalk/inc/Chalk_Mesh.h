#ifndef _H_CHALK_MESH
#define _H_CHALK_MESH

#include "Rock.h"
#include "Chalk_Defines.h"

using namespace Rock;

namespace Chalk {

    class CHALK_API Mesh {
    public:
        Mesh();
        virtual ~Mesh();

    private:
        Mesh(Mesh const&);
        Mesh& operator=(Mesh const&);
    };
};

#endif // _H_CHALK_MESH