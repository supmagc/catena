#ifndef _H_CHALK_D3D9_SHADER
#define _H_CHALK_D3D9_SHADER

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

using namespace Rock;

namespace Chalk {

    namespace D3d9 {

        class Device;

        class CHALK_D3D9_API Shader : public Chalk::Shader {
        public:
            Shader(Device* pDevice);
            virtual ~Shader();

            virtual RBOOL Load();
            virtual RBOOL Set();

        private:
            struct ShaderImpl;
            ShaderImpl* m_pImpl;

            Shader(Shader const&);
            Shader& operator=(Shader const&);
        };
    };
};

#endif // _H_CHALK_D3D9_SHADER