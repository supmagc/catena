#ifndef _H_ROCK_TYPEDEFS
#define _H_ROCK_TYPEDEFS 1

namespace Rock {

#ifdef _WINDOWS
    typedef int_least8_t RINT8;
    typedef uint_least8_t RUINT8;
    typedef int_least16_t RINT16;
    typedef uint_least16_t RUINT16;
    typedef int_least32_t RINT32;
    typedef uint_least32_t RUINT32;
    typedef int_least64_t RINT64;
    typedef uint_least64_t RUINT64;
    typedef RINT32 RINT;
    typedef RUINT32 RUINT;
    typedef char RBYTE;
	typedef wchar_t RCHAR;
	typedef float RFLOAT;
    typedef double RDOUBLE;
    typedef bool RBOOL;

	const RINT8 RINT8_MIN = INT8_MIN; // Considered -(2^7-1)
	const RINT8 RINT8_MAX = INT8_MAX; // Considered 2^7-1
	const RUINT8 RUINT8_MAX = UINT8_MAX; // Considered 2^2-1
	const RINT16 RINT16_MIN = SHRT_MIN; // Considered -(2^15-1)
	const RINT16 RINT16_MAX = SHRT_MAX; // Considered 2^15-1
	const RUINT16 RUINT16_MAX = USHRT_MAX; // Considered 2^16-1
	const RINT32 RINT32_MIN = LONG_MIN; // Considered -(2^31-1)
	const RINT32 RINT32_MAX = LONG_MAX; // Considered 2^31-1
	const RUINT32 RUINT32_MAX = ULONG_MAX; // Considered 2^32-1
	const RINT64 RINT64_MIN = LLONG_MIN; // Considered -(2^63-1)
	const RINT64 RINT64_MAX = LLONG_MAX; // Considered 2^63-1
	const RUINT64 RUINT64_MAX = ULLONG_MAX; // Considered 2^64-1

	const RFLOAT RFLOAT_MIN = FLT_MIN; // Considered 1E-37 or greater
	const RFLOAT RFLOAT_MAX = FLT_MAX; // Considered 1E+37 or greater
	const RDOUBLE RDOUBLE_MIN = DBL_MIN; // Considered 1E+37 or smaller
	const RDOUBLE RDOUBLE_MAX = DBL_MAX; // Considered 1E-37 or smaller
	const RFLOAT RFLOAT_EPSILON = FLT_EPSILON; // considered 1E-5 or smaller
	const RFLOAT RDOUBLE_EPSILON = DBL_EPSILON; // considered 1E-9 or smaller
	const RUINT8 RFLOAT_DIGITS = FLT_DIG; // considered 6 or greater
	const RUINT8 RDOUBLE_DIGITS = DBL_DIG; // considered 10 or greater

#ifndef _SWIG
    #ifdef _WIN32
        typedef int *__ptr32 RPTR;
    #else
        typedef int *__ptr64 RPTR;
    #endif
#endif // _SWIG
#endif // _WINDOWS

    typedef void* RBOX;
    typedef void const* RCBOX;
};

#define RNULL 0
#define RINT_SIZE sizeof(Rock::RINT)
#define RUINT_SIZE sizeof(Rock::RUINT)
#define RFLOAT_SIZE sizeof(Rock::RFLOAT)
#define RDOUBLE_SIZE sizeof(Rock::RDOUBLE)
#define RCHAR_SIZE sizeof(Rock::RCHAR)

#define RINT_MIN INT_MIN
#define RINT_MAX INT_MAX
#define RUINT_MIN 0
#define RUINT_MAX UINT_MAX

#endif // _H_ROCK_TYPES