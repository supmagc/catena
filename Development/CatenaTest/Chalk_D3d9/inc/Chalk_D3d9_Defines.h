#ifndef _H_CHALK_D3D9_DEFINES
#define _H_CHALK_D3D9_DEFINES

#include "Rock.h"

#if CHALK_D3D9_EXPORTS
    #define CHALK_D3D9_API DLL_EXPORT
#else
    #define CHALK_D3D9_API DLL_IMPORT
#endif

#endif // _H_CHALK_D3D9_DEFINES