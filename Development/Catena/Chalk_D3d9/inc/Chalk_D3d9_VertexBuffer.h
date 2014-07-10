#ifndef _H_CHALK_D3D9_MESH
#define _H_CHALK_D3D9_MESH

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

using namespace Rock;

namespace Chalk {

    namespace D3d9 {

        class Device;

        class CHALK_D3D9_API VertexBuffer : public Chalk::IVertexBuffer {
        public:
            VertexBuffer(Device* pDevice);

            virtual void Release();
            virtual IDevice* GetDevice();
            virtual IDevice const* GetDevice() const;
            virtual void OnDeviceLost();
            virtual void OnDeviceReset();

            virtual RBOOL Load();
            virtual RBOOL Set();

        protected:
            virtual ~VertexBuffer();

        private:
            PIMPL_DECL(VertexBuffer);

            VertexBuffer(VertexBuffer const&);
            VertexBuffer& operator=(VertexBuffer const&);
        };
    };
};

#endif // _H_CHALK_D3D9_MESH