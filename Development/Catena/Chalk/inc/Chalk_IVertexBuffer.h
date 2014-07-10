#ifndef _H_CHALK_IVERTEXBUFFER
#define _H_CHALK_IVERTEXBUFFER 1

#include "Rock.h"
#include "Chalk_Defines.h"
#include "Chalk_IResource.h"

namespace Chalk {

    class CHALK_API IVertexBuffer : public IResource{
    public:
        IVertexBuffer() {}

        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;

    protected:
        virtual ~IVertexBuffer() {}

    private:
        IVertexBuffer(IVertexBuffer const&);
        IVertexBuffer& operator=(IVertexBuffer const&);
    };
};

#endif // _H_CHALK_IVERTEXBUFFER