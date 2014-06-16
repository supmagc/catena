#ifndef _H_ROCK_STD
#define _H_ROCK_STD

#include "Rock_Defines.h"

// C includes
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cwchar>

// Memory utilities
#include <malloc.h>
#include <memory.h>

// stl includes
#include <iostream>
#include <vector>
#include <list>
#include <map>


using namespace std;

// System specific includes
#ifdef _WINDOWS
    #define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
    #include <Windows.h>
#else
    #error _ERROR_WINDOWS_ONLY
#endif

#endif // _H_ROCK_STD