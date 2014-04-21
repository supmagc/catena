#ifndef _H_DIAMOND_DEFINES
#define _H_DIAMOND_DEFINES

#include "Rock.h"

#if DIAMOND_EXPORTS
    #define DIAMOND_API DLL_EXPORT
#else
    #define DIAMOND_API DLL_IMPORT
#endif

#endif