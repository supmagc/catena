
#include "Rock_Std.h"
#include "Rock_Assert.h"
#include "Rock_Types.h"
#include "Rock_Defines.h"
#include "Rock_String.h"
#include "Rock_Log.h"

namespace Rock {

    ROCK_API void rAssert(String const& sExpression, String const& sFile, int nLine) {
        rLog(LogType::LT_ASSERT, String(RTXT("Assert")), Rock::String("Assertion failed:\n") + sExpression, sFile, nLine);
        if(MessageBoxW(RNULL, *sExpression, RTXT("Assertion failed:"), MB_OKCANCEL) == MB_OK)
            BREAK;
    }
};