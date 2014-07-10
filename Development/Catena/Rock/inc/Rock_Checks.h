#ifndef _H_ROCK_ASSERT
#define _H_ROCK_ASSERT

#include "Rock_String.h"
#include "Rock_Defines.h"
#include "Rock_Functions.h"

#define CHECK_ALWAYS(e) if(!(e)) Rock::catAssert(#e, __FILE__, __LINE__)

#ifdef _CHECKS_SLOW
#define CHECK_SLOW(e) CHECK_ALWAYS((e) == true)
#define CHECK_SLOW_TRUE(e) CHECK_ALWAYS((e) == true)
#define CHECK_SLOW_FALSE(e) CHECK_ALWAYS((e) == false)
#define CHECK_SLOW_NULL(e) CHECK_ALWAYS((e) == RNULL)
#define CHECK_SLOW_NOTNULL(e) CHECK_ALWAYS((e) != RNULL)
#else
#define CHECK_SLOW(e) 
#define CHECK_SLOW_TRUE(e) 
#define CHECK_SLOW_FALSE(e) 
#define CHECK_SLOW_NULL(e) 
#define CHECK_SLOW_NOTNULL(e) 
#endif

#ifdef _CHECKS_DEFAULT
#define CHECK(e) CHECK_ALWAYS((e) == true)
#define CHECK_TRUE(e) CHECK_ALWAYS((e) == true)
#define CHECK_FALSE(e) CHECK_ALWAYS((e) == false)
#define CHECK_NULL(e) CHECK_ALWAYS((e) == RNULL)
#define CHECK_NOTNULL(e) CHECK_ALWAYS((e) != RNULL)
#else
#define CHECK(e) 
#define CHECK_TRUE(e) 
#define CHECK_FALSE(e) 
#define CHECK_NULL(e) 
#define CHECK_NOTNULL(e) 
#endif

#endif  // _H_ROCK_ASSERT