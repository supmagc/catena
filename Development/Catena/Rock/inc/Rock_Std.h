#ifndef _H_ROCK_STD
#define _H_ROCK_STD

#include "Rock_Defines.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>

#include <iostream>

#ifdef _WINDOWS
    #define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
    #include <Windows.h>
#else
    #error _ERROR_WINDOWS_ONLY
#endif

#endif // _H_ROCK_STD