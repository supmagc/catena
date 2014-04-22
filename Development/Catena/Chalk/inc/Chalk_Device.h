#ifndef _H_CHALK_DEVICE
#define _H_CHALK_DEVICE

#include "Rock.h"
#include "Chalk_Defines.h"

using namespace Rock;

namespace Chalk {

    class CHALK_API Device {
    public:
        Device();
        virtual ~Device();

        virtual RBOOL Create() =0;
        virtual RBOOL BackBufferClear() =0;
        virtual RBOOL BackBufferSwitch() =0;
        virtual void Destroy() =0;

    private:
        Device(Device const&);
        Device& operator=(Device const&);
    };
};

#endif // _H_CHALK_DEVICE