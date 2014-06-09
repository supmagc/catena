#ifndef _H_ROCK_ASSERT
#define _H_ROCK_ASSERT

#include "Rock_String.h"
#include "Rock_Defines.h"

namespace Rock {

    ROCK_API void rAssert(String const& sExpression, String const& sFile, int nLine);
};

#ifdef _ASSERT
    #define ASSERT(e) if(!(e)) rAssert(#e, __FILE__, __LINE__)
#else
    #define ASSERT(e) 
#endif

#endif  // _H_ROCK_ASSERT