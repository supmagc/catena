#ifndef _H_CHALK_IVERTEXBUFFER
#define _H_CHALK_IVERTEXBUFFER 1

#include "Rock.h"
#include "Chalk_Defines.h"
#include "Chalk_IResource.h"

namespace Chalk {

    class CHALK_API IVertexBuffer : public IResource{
    public:
        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;
    };
};

#endif // _H_CHALK_IVERTEXBUFFER