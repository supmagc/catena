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
            virtual ~IndexBuffer();

            virtual RBOOL Load();
            virtual RBOOL Set();

        private:
            PIMPL_DECL(IndexBuffer);

            IndexBuffer(IndexBuffer const&);
            IndexBuffer& operator=(IndexBuffer const&);
        };
    };
};

#endif // _H_CHALK_D3D9_INDEXBUFFER