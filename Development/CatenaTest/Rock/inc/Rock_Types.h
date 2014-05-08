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

    #if defined(_WIN32)
//        typedef int *__ptr32 PTR;
    #else
//        typedef int *__ptr64 PTR;
    #endif

#endif

};

#define RNULL 0
#define RFLOAT_SIZE sizeof(Rock::RFLOAT)
#define RDOUBLE_SIZE sizeof(Rock::RDOUBLE)

#endif // _H_ROCK_TYPES