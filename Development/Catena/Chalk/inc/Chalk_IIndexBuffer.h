#ifndef _H_CHALK_IINDEXBUFFER
#define _H_CHALK_IINDEXBUFFER 1

#include "Rock.h"
#include "Chalk_Defines.h"
#include "Chalk_IResource.h"

namespace Chalk {

    class CHALK_API IIndexBuffer : public IResource {
    public:
        IIndexBuffer() {}

        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;

    protected:
        virtual ~IIndexBuffer() {}

    private:
        IIndexBuffer(IIndexBuffer const&);
        IIndexBuffer& operator=(IIndexBuffer const&);
    };
}

#endif // _H_CHALK_IINDEXBUFFER