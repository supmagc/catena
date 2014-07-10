#ifndef _H_ROCK_FUNCTIONS
#define _H_ROCK_FUNCTIONS 1

#include "Rock_Defines.h"
#include "Rock_Types.h"
#include "Rock_String.h"

namespace Rock {

    // Debug stuff, no need to inline
    ROCK_API void catDebugBreak();
    ROCK_API void catOutputLog(String const& sLog);
    ROCK_API void catAssert(String const& sExpression, String const& sFile, int nLine);

    // More complex helper functions, not used frequent, not inlined
    ROCK_API String catWorkingDirectory();
    ROCK_API String catCommandLine();
    ROCK_API void catMessageBoxInfo(String const& sTitle, String const& sMessage);
    ROCK_API void catMessageBoxWarning(String const& sTitle, String const& sMessage);
    ROCK_API void catMessageBoxAlert(String const& sTitle, String const& sMessage);
    ROCK_API RBOOL catMessageBoxConfirm(String const& sTitle, String const& sMessage);
    ROCK_API void catPostQuitMessage(RINT nCode);

    // Memory stuff, small and used frequently
    ROCK_API FORCEINLINE RBOX catMemAlloc(RUINT nSize, RUINT nAlignment);
    ROCK_API FORCEINLINE RBOX catMemRealloc(RBOX pAdress, RUINT nSize, RUINT nAlignment);
    ROCK_API FORCEINLINE void catMemFree(RBOX pAdress);
    ROCK_API FORCEINLINE void catMemCopy(RCBOX pSrc, RBOX pDst, RUINT nLength);
    ROCK_API FORCEINLINE void catMemMove(RCBOX pSrc, RBOX pDst, RUINT nLength);
    ROCK_API FORCEINLINE void catMemZero(RBOX pDst, RUINT nLength);
    ROCK_API FORCEINLINE void catMemSet(RBOX pDst, RINT nValue, RUINT nLength);

    // Frequent helper functions
    template<typename Element>
    ROCK_API FORCEINLINE void catSwap(Element& m0, Element& m1);
    ROCK_API FORCEINLINE void catSleep(RDOUBLE nDuration);
    ROCK_API FORCEINLINE RBOOL catIsDebug();
    ROCK_API FORCEINLINE RBOOL catIsRelease();
    ROCK_API FORCEINLINE RBOOL catIsPublish();

    #include "../inl/Functions.inl"
};

#endif // _H_ROCK_FUNCTIONS