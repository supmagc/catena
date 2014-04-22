#ifndef _H_ROCK_TYPEDEFS
#define _H_ROCK_TYPEDEFS

namespace Rock {

#ifdef _WINDOWS
    typedef signed __int8 RINT8;
    typedef signed __int8 RINT8;
    typedef unsigned __int8 RUINT8;
    typedef signed __int16 RINT16;
    typedef unsigned __int16 RUINT16;
    typedef signed __int32 RINT32;
    typedef unsigned __int32 RUINT32;
    typedef signed __int64 RINT64;
    typedef unsigned __int64 RUINT64;
    typedef RINT32 RINT;
    typedef RUINT32 RUINT;
    typedef unsigned __int8 RBYTE;
    typedef wchar_t RCHAR;
    typedef float RFLOAT32;
    typedef double RFLOAT64;
    typedef RFLOAT32 RFLOAT;
    typedef RFLOAT64 RDOUBLE;
    typedef bool RBOOL;

    #ifdef _WIN32
        typedef int *__ptr32 PTR;
    #else
        typedef int *__ptr64 PTR;
    #endif

#endif

};

#define RNULL 0
#define RFLOAT_SIZE sizeof(Rock::RFLOAT)
#define RDOUBLE_SIZE sizeof(Rock::RDOUBLE)

#endif // _H_ROCK_TYPES