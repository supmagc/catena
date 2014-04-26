#ifndef _H_CHALK_IINDEXBUFFER
#define _H_CHALK_IINDEXBUFFER

#include "Rock.h"

using namespace Rock;

namespace Chalk {

    class CHALK_API IIndexBuffer {
    public:
        IIndexBuffer() {}
        virtual ~IIndexBuffer() {}

        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;

    private:
        IIndexBuffer(IIndexBuffer const&);
        IIndexBuffer& operator=(IIndexBuffer const&);
    };
}

#endif // _H_CHALK_IINDEXBUFFER