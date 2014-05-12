#ifndef _H_WOOD_DEFINES
#define _H_WOOD_DEFINES

#include "Rock.h"

#if defined(WOOD_EXPORTS)
    #define WOOD_API DLL_EXPORT
#elif defined(WOOD_IMPORTS)
    #define WOOD_API DLL_EXPORT
#else
    #define WOOD_API
#endif

#endif // _H_WOOD_DEFINES