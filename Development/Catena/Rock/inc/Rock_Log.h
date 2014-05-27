#ifndef _H_ROCK_LOG
#define _H_ROCK_LOG

#include "Rock_Std.h"
#include "Rock_String.h"
#include "Rock_Defines.h"
#include "Rock_Types.h"

using namespace Rock;

#ifdef _DEBUG
namespace Rock {
    struct ROCK_API __Logger {
        __Logger(String const& sCategory, String const& sMessage, String const& sFile, RUINT const nLine, ...) {
            String sCombined;
            va_list args;
            va_start(args, nLine);
            String sMessageTemp = Rock::String::vFormat(sMessage, args);
            va_end(args);
            if(sCategory.GetLength() > 0)
                sCombined = Rock::String::Format(RTXT("[%s] %s (line: %n) %s\n"), *sCategory, *sFile, nLine, *sMessage);
            else
                sCombined = Rock::String::Format(RTXT("%s (line: %d) %s\n"), sFile, nLine, sMessage);
            OutputDebugStringW(*sCombined);
        }
    };
};
#define LOG(m) __Logger(RTXT(""), m, __FILE__, __LINE__)
#define LOG_Mes(m) __Logger(RTXT(L""), m, __FILE__, __LINE__)
#define LOG_CatMes(c, m) __Logger(c, m, __FILE__, __LINE__)
#define LOGf(m, ...) __Logger(RTXT(""), m, __FILE__, __LINE__, __VA_ARGS__)
#define LOGf_Mes(m, ...) __Logger(RTXT(L""), m, __FILE__, __LINE__, __VA_ARGS__)
#define LOGf_CatMes(c, m, ...) __Logger(c, m, __FILE__, __LINE__, __VA_ARGS__)
#else
#define LOG(m)
#define LOG_Mes(m)
#define LOG_CatMes(c, m)
#endif // _LOG

#endif // _H_ROCK_LOG