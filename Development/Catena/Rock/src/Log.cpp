
#include "Rock_Std.h"
#include "Rock_Log.h"

namespace Rock {

    struct _Logger {

    };

    _Logger oLogger = _Logger();

    ROCK_API void rLogInit(String const& sFile, LogType const eLimit) {
    }

    ROCK_API void rLog(LogType const eType, String const& sCategory, String const& sMessage, String const& sFile, RUINT const nLine, ...) {
        String sCombined;
        va_list args;
        va_start(args, nLine);
        String sMessageTemp = Rock::String::Format(sMessage, args);
        va_end(args);
        if(sCategory.GetLength() > 0)
            sCombined = Rock::String::Format(RTXT("[%s] %s (line: %d) %s \n"), *sCategory, *sFile, nLine, *sMessageTemp);
        else
            sCombined = Rock::String::Format(RTXT("%s (line: %d) %s \n"), *sFile, nLine, *sMessageTemp);

        OutputDebugStringW(*sCombined);
    }
};
