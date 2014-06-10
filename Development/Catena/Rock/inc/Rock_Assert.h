#ifndef _H_ROCK_ASSERT
#define _H_ROCK_ASSERT

#include "Rock_String.h"
#include "Rock_Defines.h"

namespace Rock {

    ROCK_API void rAssert(String const& sExpression, String const& sFile, int nLine);
};

#ifdef _ASSERT
    #define ASSERT(e) if(!(e)) rAssert(#e, __FILE__, __LINE__)
    #define ASSERT_TRUE(e) ASSERT((e) == true)
    #define ASSERT_FALSE(e) ASSERT((e) == false)
    #define ASSERT_NULL(e) ASSERT((e) == RNULL)
    #define ASSERT_NOTNULL(e) ASSERT((e) != RNULL)
#else
    #define ASSERT(e) 
    #define ASSERT_TRUE(e) 
    #define ASSERT_FALSE(e) 
    #define ASSERT_NULL(e) 
    #define ASSERT_NOTNULL(e) 
#endif

#endif  // _H_ROCK_ASSERT