#ifndef _H_CHALK_D3D9_INDEXBUFFER
#define _H_CHALK_D3D9_INDEXBUFFER

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

using namespace Rock;

namespace Chalk {

    namespace D3d9 {

        class Device;

        class CHALK_D3D9_API IndexBuffer : public Chalk::IIndexBuffer {
        public:
            IndexBuffer(Device* pDevice);

            virtual void Release();
            virtual IDevice* GetDevice();
            virtual IDevice const* GetDevice() const;
            virtual void OnDeviceLost();
            virtual void OnDeviceReset();

            virtual RBOOL Load();
            virtual RBOOL Set();

        protected:
            virtual ~IndexBuffer();

        private:
            PIMPL_DECL(IndexBuffer);

            IndexBuffer(IndexBuffer const&);
            IndexBuffer& operator=(IndexBuffer const&);
        };
    };
};

#endif // _H_CHALK_D3D9_INDEXBUFFER