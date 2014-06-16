
#include "Rock_Std.h"
#include "Rock_Log.h"
#include "Rock_Functions.h"

namespace Rock {

    struct _Logger {

    };

    _Logger oLogger = _Logger();

    ROCK_API void catLogInit(String const& sFile, LogType const eLimit) {
    }

    ROCK_API void catLog(LogType const eType, String const& sCategory, String const& sMessage, String const& sFile, RUINT const nLine, ...) {
        String sCombined;
        va_list args;
        va_start(args, nLine);
        String sMessageTemp = Rock::String::Format(sMessage, args);
        va_end(args);
        if(sCategory.GetLength() > 0)
            sCombined = Rock::String::Format(RTXT("[%s] %s\n%s(%d)\n"), *sCategory, *sMessageTemp, *sFile, nLine);
        else
            sCombined = Rock::String::Format(RTXT("%s\n%s(%d)\n"), *sMessageTemp, *sFile, nLine);

        catOutputLog(sCombined);
    }
};
