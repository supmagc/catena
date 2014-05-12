#ifndef _H_CHALK_D3D9_DEFINES
#define _H_CHALK_D3D9_DEFINES

#include "Rock.h"

#if defined(CHALK_D3D9_EXPORTS)
    #define CHALK_D3D9_API DLL_EXPORT
#elif defined(CHALK_D3D9_IMPORTS)
    #define CHALK_D3D9_API DLL_IMPORT
#else
    #define CHALK_D3D9_API
#endif

#endif // _H_CHALK_D3D9_DEFINES