#ifndef _H_ROCK_FUNCTIONS
#define _H_ROCK_FUNCTIONS 1

#include "Rock_Defines.h"
#include "Rock_Types.h"
#include "Rock_String.h"

namespace Rock {

    ROCK_API void catDebugBreak();
    ROCK_API void catOutputLog(String const& sLog);

    ROCK_API void catMessageBoxInfo(String const& sTitle, String const& sMessage);
    ROCK_API void catMessageBoxWarning(String const& sTitle, String const& sMessage);
    ROCK_API void catMessageBoxAlert(String const& sTitle, String const& sMessage);
    ROCK_API RBOOL catMessageBoxConfirm(String const& sTitle, String const& sMessage);

    ROCK_API String catWorkingDirectory();
    ROCK_API String catCommandLine();

    ROCK_API RBOOL catIsDebug();
    ROCK_API RBOOL catIsRelease();
    ROCK_API RBOOL catIsPublish();

    ROCK_API void catPostQuitMessage(RINT nCode);
    ROCK_API void catSleep(RDOUBLE nDuration);
};

#endif // _H_ROCK_FUNCTIONS