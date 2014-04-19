#ifndef _H_ROCK_STD
#define _H_ROCK_STD

#include "RockDefines.h"

#ifdef _WINDOWS
	#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
    #include <Windows.h>
#else
    #error _ERROR_WINDOWS_ONLY
#endif

#endif // _H_ROCK_STD