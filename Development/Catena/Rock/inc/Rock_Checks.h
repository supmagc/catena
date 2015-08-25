#ifndef _H_ROCK_ASSERT
#define _H_ROCK_ASSERT

#include "Rock_String.h"
#include "Rock_Defines.h"
#include "Rock_Functions.h"

#define CHECK_ALWAYS(e) if(!(e)) Rock::catAssert(#e, __FILE__, __LINE__)

#ifdef _CHECKS_SLOW
#define CHECK_SLOW(e) CHECK_ALWAYS((RBOOL)(e) == true)
#define CHECK_SLOW_TRUE(e) CHECK_ALWAYS((RBOOL)(e) == true)
#define CHECK_SLOW_FALSE(e) CHECK_ALWAYS((RBOOL)(e) == false)
#define CHECK_SLOW_NULL(e) CHECK_ALWAYS((e) == RNULL)
#define CHECK_SLOW_NOTNULL(e) CHECK_ALWAYS((e) != RNULL)
#define CHECK_SLOW_EQUAL(e, o) CHECK_ALWAYS((e) == (o))
#define CHECK_SLOW_NOTEQUAL(e, o) CHECK_ALWAYS((e) != (o))
#define CHECK_RESULT_SLOW(e) CHECK_ALWAYS((RBOOL)(e) == true)
#define CHECK_RESULT_SLOW_TRUE(e) CHECK_ALWAYS((RBOOL)(e) == true)
#define CHECK_RESULT_SLOW_FALSE(e) CHECK_ALWAYS((RBOOL)(e) == false)
#define CHECK_RESULT_SLOW_NULL(e) CHECK_ALWAYS((e) == RNULL)
#define CHECK_RESULT_SLOW_NOTNULL(e) CHECK_ALWAYS((e) != RNULL)
#define CHECK_RESULT_SLOW_EQUAL(e, o) CHECK_ALWAYS((e) == (o))
#define CHECK_RESULT_SLOW_NOTEQUAL(e, o) CHECK_ALWAYS((e) != (o))
#else
#define CHECK_SLOW(e) 
#define CHECK_SLOW_TRUE(e) 
#define CHECK_SLOW_FALSE(e) 
#define CHECK_SLOW_NULL(e) 
#define CHECK_SLOW_NOTNULL(e) 
#define CHECK_SLOW_EQUAL(e, o)
#define CHECK_SLOW_NOTEQUAL(e, o)
#define CHECK_RESULT_SLOW(e) e
#define CHECK_RESULT_SLOW_TRUE(e) e
#define CHECK_RESULT_SLOW_FALSE(e) e
#define CHECK_RESULT_SLOW_NULL(e) e
#define CHECK_RESULT_SLOW_NOTNULL(e) e
#define CHECK_RESULT_SLOW_EQUAL(e, o) e
#define CHECK_RESULT_SLOW_NOTEQUAL(e, o) e
#endif

#ifdef _CHECKS_DEFAULT
#define CHECK(e) CHECK_ALWAYS((RBOOL)(e) == true)
#define CHECK_TRUE(e) CHECK_ALWAYS((RBOOL)(e) == true)
#define CHECK_FALSE(e) CHECK_ALWAYS((RBOOL)(e) == false)
#define CHECK_NULL(e) CHECK_ALWAYS((e) == RNULL)
#define CHECK_NOTNULL(e) CHECK_ALWAYS((e) != RNULL)
#define CHECK_EQUAL(e, o) CHECK_ALWAYS((e) == (o))
#define CHECK_NOTEQUAL(e, o) CHECK_ALWAYS((e) != (o))
#define CHECK_RESULT(e) CHECK_ALWAYS((RBOOL)(e) == true)
#define CHECK_RESULT_TRUE(e) CHECK_ALWAYS((RBOOL)(e) == true)
#define CHECK_RESULT_FALSE(e) CHECK_ALWAYS((RBOOL)(e) == false)
#define CHECK_RESULT_NULL(e) CHECK_ALWAYS((e) == RNULL)
#define CHECK_RESULT_NOTNULL(e) CHECK_ALWAYS((e) != RNULL)
#define CHECK_RESULT_EQUAL(e, o) CHECK_ALWAYS((e) == (o))
#define CHECK_RESULT_NOTEQUAL(e, o) CHECK_ALWAYS((e) != (o))
#else
#define CHECK(e) 
#define CHECK_TRUE(e) 
#define CHECK_FALSE(e) 
#define CHECK_NULL(e) 
#define CHECK_NOTNULL(e) 
#define CHECK_EQUAL(e, o)
#define CHECK_NOTEQUAL(e, o)
#define CHECK_RESULT(e) e
#define CHECK_RESULT_TRUE(e) e
#define CHECK_RESULT_FALSE(e) e
#define CHECK_RESULT_NULL(e) e
#define CHECK_RESULT_NOTNULL(e) e
#define CHECK_RESULT_EQUAL(e, o) e
#define CHECK_RESULT_NOTEQUAL(e, o) e
#endif

#endif  // _H_ROCK_ASSERT