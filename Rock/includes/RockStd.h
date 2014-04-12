#if defined(DEBUG) && !defined(_DEBUG)
	#define _DEBUG
#endif

#if defined(_ASSERT) && defined(NASSERT)
	#error You shoulnd't run this code when both _ASSERT and NASSERT are defined.
#endif

#if defined(_DEBUG) && defined(NDEBUG)
	#error You shoulnd't run this code when both _DEBUG and NDEBUG are defined.
#endif

#if !defined(_WINDOWS) && (defined(_WIN32) || defined(_WIN64))
	#define _WINDOWS
#endif

#define _WINDOWS_ONLY_MESSAGE This code is only implemented to compile under windows.

#ifdef _WINDOWS
	#include <Windows.h>
#else
	#error _WINDOWS_ONLY_MESSAGE
#endif

#include "Defines.h"
#include "TypeDefs.h"
#include "Exceptions.h"
#include "Str.h"

#ifdef ROCK_EXPORTS
#define ROCK_API DLL_EXPORT
#else
#define ROCK_API DLL_IMPORT
#pragma comment(lib, "Rock")
#endif