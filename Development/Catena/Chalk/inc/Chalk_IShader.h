#ifndef _H_CHALK_ISHADER
#define _H_CHALK_ISHADER 1

#include "Rock.h"
#include "Chalk_Defines.h"
#include "Chalk_IResource.h"

namespace Chalk {

    class CHALK_API IShader : public IResource{
    public:
        IShader() {}

        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;
        virtual IDevice* GetDevice() =0;
        virtual void SetData(RINT const*, RUINT nLength = 1) =0;
        virtual void SetData(RFLOAT const*, RUINT nLength = 1) =0;

    protected:
        virtual ~IShader() {}

    private:
        CLASS_NOCOPY(IShader);
    };
};

#endif // _H_CHALK_ISHADER