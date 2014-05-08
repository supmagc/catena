#ifndef _H_ROCK_VECTOR4
#define _H_ROCK_VECTOR4

#include "Rock_Types.h"

namespace Rock {

    struct Vector3;

    struct DLL_EXPORT Vector4 {

        RFLOAT x, y, z, w;

        Vector4();
        Vector4(RFLOAT v);
        Vector4(Vector4 const& vVector);
        Vector4(Vector3 const& vVector, RFLOAT w = 1.0f);
        Vector4(RFLOAT x, RFLOAT y, RFLOAT z, RFLOAT w = 1.0f);
        ~Vector4();

        inline RFLOAT Dot(Vector4 const& vVector) const;
        inline void Dot(Vector4 const& vVector, RFLOAT& o_nDot) const;

        inline Vector4& operator=(Vector4 const& vVector);
    };

    inline ROCK_API RFLOAT Dot(Vector4 const& vVector0, Vector4 const& vVector1);

    typedef Vector4 RVector4;

    #include "../inl/Vector4.inl"
};

#endif // _H_ROCK_VECTOR4