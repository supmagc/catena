#ifndef _H_CHALK_DEFINES
#define _H_CHALK_DEFINES 1

#include "Rock.h"

#if defined(CHALK_EXPORTS)
    #define CHALK_API DLL_EXPORT
#elif defined(CHALK_IMPORTS)
    #define CHALK_API DLL_IMPORT
#else
    #define CHALK_API
#endif

#endif // _H_CHALK_DEFINES