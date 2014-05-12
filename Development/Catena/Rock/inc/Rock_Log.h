#ifndef _H_ROCK_LOG
#define _H_ROCK_LOG

#include "Rock_Std.h"
#include "Rock_String.h"
#include "Rock_Types.h"

using namespace Rock;

#ifdef _DEBUG
namespace Rock {
	struct ROCK_API __Logger {
		__Logger(String const& sCategory, String const& sMessage, String const& sFile, RUINT const nLine) {
			String sCombined = L"[" + sCategory.ToUpper() + L"] " + sFile + L" (line: " + nLine + L") " + sMessage + L"\n";
			OutputDebugStringW(sCombined.GetData());
		}
	};
};
#define LOG(m) __Logger(L"", m, __FILE__, __LINE__)
#define LOG_M(m) __Logger(L"", m, __FILE__, __LINE__)
#define LOG_CM(c, m) __Logger(c, m, __FILE__, __LINE__)
#else
#define LOG(m)
#define LOG_M(m)
#define LOG_CM(c, m)
#endif // _LOG

#endif // _H_ROCK_LOG