#ifndef _H_ROCK_VECTOR4
#define _H_ROCK_VECTOR4

#include "Rock_Types.h"

namespace Rock {

    struct DLL_EXPORT Vector4 {

        RFLOAT x, y, z, w;

        Vector4();
        Vector4(RFLOAT x, RFLOAT y, RFLOAT z, RFLOAT w);
        Vector4(Vector4 const& vCopy);
        Vector4& operator=(Vector4 const& vCopy);
    };

    typedef Vector4 RVector4;
};

#endif // _H_ROCK_VECTOR4