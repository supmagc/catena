#ifndef _H_CHALK_ISHADER
#define _H_CHALK_ISHADER

#include "Rock.h"
#include "Chalk_Defines.h"

using namespace Rock;

namespace Chalk {

    class CHALK_API IShader {
    public:
        IShader() {}
        virtual ~IShader() {}

        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;
        virtual IDevice* GetDevice() =0;

    private:
        IShader(IShader const&);
        IShader& operator=(IShader const&);
    };
};

#endif // _H_CHALK_ISHADER