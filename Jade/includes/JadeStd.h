#include "Rock.h"
#include "Exceptions.h"

#ifdef JADE_EXPORTS
#define JADE_API DLL_EXPORT
#else
#define JADE_API DLL_IMPORT
#pragma comment(lib, "Jade")
#endif