#ifndef _H_CHALK_SHADER
#define _H_CHALK_SHADER

#include "Rock.h"
#include "Chalk_Defines.h"

using namespace Rock;

namespace Chalk {

    class CHALK_API Shader {
    public:
        Shader();
        virtual ~Shader();

        virtual RBOOL Load() =0;
        virtual RBOOL Set() =0;

    private:
        Shader(Shader const&);
        Shader& operator=(Shader const&);
    };
};

#endif // _H_CHALK_SHADER