#ifndef _H_ROCK_LOG
#define _H_ROCK_LOG

#include "Rock_Std.h"
#include "Rock_String.h"
#include "Rock_Defines.h"
#include "Rock_Types.h"

namespace Rock {

    enum class LogType {
        LT_DEBUG = 0,
        LT_ASSERT,
        LT_INFO,
        LT_WARNING,
        LT_ERROR,
        LT_SYSTEM
    };

    ROCK_API void rLogInit(String const& sFile, LogType const eLimit = LogType::LT_DEBUG);
    ROCK_API void rLog(LogType const eType, String const& sCategory, String const& sMessage, String const& sFile, RUINT const nLine, ...);
};

#ifdef _DEBUG
    #define LOG_DEBUG(m, ...) Rock::rLog(Rock::LogType::LT_DEBUG, RTXT(""), m, __FILE__, __LINE__, __VA_ARGS__)
    #define LOGCAT_DEBUG(c, m, ...) Rock::rLog(Rock::LogType::LT_DEBUG, c, m, __FILE__, __LINE__, __VA_ARGS__)
#else
    #define LOG_DEBUG(m, ...) 
    #define LOGCAT_DEBUG(c, m, ...) 
#endif

#ifndef _PUBLISH
    #define LOG_INFO(m, ...) Rock::rLog(Rock::LogType::LT_INFO, RTXT(""), m, __FILE__, __LINE__, __VA_ARGS__)
    #define LOGCAT_INFO(c, m, ...) Rock::rLog(Rock::LogType::LT_INFO, c, m, __FILE__, __LINE__, __VA_ARGS__)
    #define LOG_WARNING(m, ...) Rock::rLog(Rock::LogType::LT_WARNING, RTXT(""), m, __FILE__, __LINE__, __VA_ARGS__)
    #define LOGCAT_WARNING(c, m, ...) Rock::rLog(Rock::LogType::LT_WARNING, c, m, __FILE__, __LINE__, __VA_ARGS__)
#else
    #define LOG_INFO(m, ...) 
    #define LOGCAT_INFO(c, m, ...) 
    #define LOG_WARNING(m, ...) 
    #define LOGCAT_WARNING(c, m, ...) 
#endif

#define LOG_ERROR(m, ...) Rock::rLog(Rock::LogType::LT_ERROR, RTXT(""), m, __FILE__, __LINE__, __VA_ARGS__)
#define LOGCAT_ERROR(c, m, ...) Rock::rLog(Rock::LogType::LT_ERROR, c, m, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_SYSTEM(m, ...) Rock::rLog(Rock::LogType::LT_SYSTEM, RTXT(""), m, __FILE__, __LINE__, __VA_ARGS__)
#define LOGCAT_SYSTEM(c, m, ...) Rock::rLog(Rock::LogType::LT_SYSTEM, c, m, __FILE__, __LINE__, __VA_ARGS__)

#endif // _H_ROCK_LOG