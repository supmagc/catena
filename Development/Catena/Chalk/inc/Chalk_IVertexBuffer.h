#ifndef _H_CHALK_MESH
#define _H_CHALK_MESH

#include "Rock.h"
#include "Chalk_Defines.h"

using namespace Rock;

namespace Chalk {

    class CHALK_API IVertexBuffer {
    public:
        IVertexBuffer() {}
        virtual ~IVertexBuffer() {}

        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;

    private:
        IVertexBuffer(IVertexBuffer const&);
        IVertexBuffer& operator=(IVertexBuffer const&);
    };
};

#endif // _H_CHALK_MESH