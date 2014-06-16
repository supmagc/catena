#ifndef _H_CHALK_D3D9_RESOURCE
#define _H_CHALK_D3D9_RESOURCE 1

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

namespace Chalk {

    namespace D3d9 {

        class Device;

        class CHALK_D3D9_API Resource : public IResource {
        public:
            Resource(Device* pDevice);

            virtual void Release();
            virtual Device* GetDevice();
            virtual void OnDeviceLost();
            virtual void OnDeviceReset();

        protected:
            Device* pDevice;
            virtual ~Resource();

        private:
            CLASS_NOCOPY(Resource);
        };
    };
};

#endif // _H_CHALK_D3D9_RESOURCE