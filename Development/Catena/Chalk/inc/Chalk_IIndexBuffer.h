#ifndef _H_CHALK_IINDEXBUFFER
#define _H_CHALK_IINDEXBUFFER 1

#include "Rock.h"
#include "Chalk_Defines.h"
#include "Chalk_IResource.h"

namespace Chalk {

    class CHALK_API IIndexBuffer : public IResource {
    public:
        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;
    };
}

#endif // _H_CHALK_IINDEXBUFFER