#ifndef _H_ROCK_VECTOR3
#define _H_ROCK_VECTOR3

#include "Rock_Types.h"

namespace Rock {

    struct DLL_EXPORT Vector3 {

        RFLOAT x, y, z;

        Vector3();
        Vector3(RFLOAT x, RFLOAT y, RFLOAT z);
        Vector3(Vector3 const& vCopy);
        Vector3& operator=(Vector3 const& vCopy);
    };

    typedef Vector3 RVector3;
    typedef Vector3 Vector;
    typedef Vector RVector;
};

#endif // _H_ROCK_VECTOR3