#ifndef _H_ROCK_LOG
#define _H_ROCK_LOG

#include "Rock_Std.h"
#include "Rock_String.h"
#include "Rock_Types.h"

using namespace Rock;

#ifdef _LOG
namespace Rock {
	struct ROCK_API __Logger {
		__Logger(String const& sMessage) : this(String(L"Unknown"), sMessage) {}
		__Logger(String const& sCategory, String const& sMessage)) : this(sCategory, sMessage, L"", 0) {}
		__Logger(String const& sMessage, String const& sFile, RUINT const nLine) : this(String(L"Unknown"), sMessage, sFile, nLine) {}
		__Logger(String const& sCategory, String const& sMessage, String const& sFile, RUINT const nLine) {
			String sCombined = L"[" + sCategory.ToUpper() + L"] " + sFile + L" (line: " + nLine + L") " + sMessage + L"\n";
			OutputDebugStringW(sCombined.GetData());
		}
	};
};
#define LOG(m) __Logger(m)
#define LOG(c, m) __Logger(c, m)
#else
#define LOG(m)
#endif // _LOG

#endif // _H_ROCK_LOG