#ifndef _H_WOOD_WINDOWS_DEFINES
#define _H_WOOD_WINDOWS_DEFINES

#include "Rock.h"

#if defined(WOOD_WINDOWS_EXPORTS)
    #define WOOD_WINDOWS_API DLL_EXPORT
#elif defined(WOOD_WINDOWS_IMPORTS)
    #define WOOD_WINDOWS_API DLL_EXPORT
#else
    #define WOOD_WINDOWS_API
#endif

#endif // _H_WOOD_WINDOWS_DEFINES