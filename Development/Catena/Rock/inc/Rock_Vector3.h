#ifndef _H_ROCK_VECTOR3
#define _H_ROCK_VECTOR3

#include "Rock_Types.h"

namespace Rock {

    struct DLL_EXPORT Vector3 {

        RFLOAT x, y, z;
    };

    typedef Vector3 RVector3;
    typedef Vector3 Vector;
    typedef Vector RVector;
};

#endif // _H_ROCK_VECTOR3