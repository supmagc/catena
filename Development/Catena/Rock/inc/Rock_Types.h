#ifndef _H_ROCK_TYPEDEFS
#define _H_ROCK_TYPEDEFS

namespace Rock {

#if defined(_WINDOWS)
    typedef signed char RINT8;
    typedef unsigned char RUINT8;
    typedef signed short RINT16;
    typedef unsigned short RUINT16;
    typedef signed int RINT32;
    typedef unsigned int RUINT32;
    typedef signed long RINT64;
    typedef unsigned long RUINT64;
    typedef RINT32 RINT;
    typedef RUINT32 RUINT;
    typedef unsigned char RBYTE;
    typedef wchar_t RCHAR;
    typedef float RFLOAT;
    typedef double RDOUBLE;
    typedef bool RBOOL;

#ifndef SWIG
    #if defined(_WIN32)
        typedef int *__ptr32 RPTR;
    #else
        typedef int *__ptr64 RPTR;
    #endif
#endif

    typedef void* RBOX;
    typedef void const* RCBOX;

#endif

};

#define RNULL 0
#define RFLOAT_SIZE sizeof(Rock::RFLOAT)
#define RDOUBLE_SIZE sizeof(Rock::RDOUBLE)

#endif // _H_ROCK_TYPES