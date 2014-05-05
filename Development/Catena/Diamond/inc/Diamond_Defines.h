#ifndef _H_DIAMOND_DEFINES
#define _H_DIAMOND_DEFINES

#include "Rock.h"

#if defined(DIAMOND_EXPORTS)
    #define DIAMOND_API DLL_EXPORT
#elif defined(IDAMOND_IMPORTS)
    #define DIAMOND_API DLL_IMPORT
#else
    #define DIAMOND_API
#endif

#endif