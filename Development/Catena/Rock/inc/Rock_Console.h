#ifndef _H_ROCK_CONSOLE
#define _H_ROCK_CONSOLE 1

#include "Rock_Std.h"
#include "Rock_Types.h"
#include "Rock_Defines.h"

namespace Rock {

	class ROCK_API Console {
	public:
		enum class Color : RBYTE {
			BLACK = 0x00,
			RED = 0x04,
			GREEN = 0x02,
			BLUE = 0x01,
			YELLOW = 0x06,
			MAGENTA = 0x05,
			CYAN = 0x03,
			WHITE = 0x07,
		};

		Console();
		~Console();

		void AttachToStdOut();
		void SetColor(Color eForegroundColor, RBOOL bForegroundIntens, Color eBackgroundColor, RBOOL bBackgroundIntens);
		void Write(String const& sData);

	private:
		static HANDLE s_hConsole;
		static RUINT32 s_nInstanceCount;

		CLASS_NOCOPY(Console);
	};
};

#endif // _H_ROCK_CONSOLE