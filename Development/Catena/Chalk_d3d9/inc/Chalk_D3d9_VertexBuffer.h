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
            virtual ~VertexBuffer();

            virtual RBOOL Load();
            virtual RBOOL Set();

        private:
            struct VertexBufferImpl;
            VertexBufferImpl* m_pImpl;

            VertexBuffer(VertexBuffer const&);
            VertexBuffer& operator=(VertexBuffer const&);
        };
    };
};

#endif // _H_CHALK_D3D9_MESH