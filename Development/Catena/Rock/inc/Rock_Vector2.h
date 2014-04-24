#ifndef _H_ROCK_VECTOR2
#define _H_ROCK_VECTOR2

#include "Rock_Types.h"

namespace Rock {

    struct DLL_EXPORT Vector2 {

        RFLOAT x, y;

        Vector2();
        Vector2(RFLOAT x, RFLOAT y);
        Vector2(Vector2 const& vCopy);
        Vector2& operator=(Vector2 const& vCopy);
    };

    typedef Vector2 RVector2;
};

#endif // _H_ROCK_VECTOR3