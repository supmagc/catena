
#include "Rock_Std.h"
#include "Rock_Assert.h"
#include "Rock_Types.h"
#include "Rock_Defines.h"
#include "Rock_String.h"
#include "Rock_Log.h"
#include "Rock_Functions.h"

namespace Rock {

    ROCK_API void catAssert(String const& sExpression, String const& sFile, int nLine) {
        catLog(LogType::LT_ASSERT, String(RTXT("Assert")), sExpression, sFile, nLine);
        if(catMessageBoxConfirm(RTXT("Assertion failed:"), sExpression))
            BREAK_ALWAYS;
    }
};