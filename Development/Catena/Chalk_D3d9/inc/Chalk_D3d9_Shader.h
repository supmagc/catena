#ifndef _H_CHALK_D3D9_SHADER
#define _H_CHALK_D3D9_SHADER

#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9_Defines.h"

using namespace Rock;

namespace Chalk {

    namespace D3d9 {

        class Device;

        class CHALK_D3D9_API Shader : public Chalk::IShader {
        public:
            Shader(Device* pDevice);

            virtual void Release();
            virtual IDevice* GetDevice();
            virtual IDevice const* GetDevice() const;
            virtual void OnDeviceLost();
            virtual void OnDeviceReset();

            virtual RBOOL Load();
            virtual RBOOL Set();
            virtual void SetData(RINT const*, RUINT nLength = 1);
            virtual void SetData(RFLOAT const*, RUINT nLength = 1);

        protected:
            virtual ~Shader();

        private:
            struct ShaderImpl;
            ShaderImpl* m_pImpl;

            Shader(Shader const&);
            Shader& operator=(Shader const&);
        };
    };
};

#endif // _H_CHALK_D3D9_SHADER