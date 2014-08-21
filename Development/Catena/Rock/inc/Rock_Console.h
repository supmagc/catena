#ifndef _H_ROCK_CONSOLE
#define _H_ROCK_CONSOLE 1

#include "Rock_Std.h"
#include "Rock_Types.h"
#include "Rock_Defines.h"

namespace Rock {

	class ROCK_API Console {
	public:
		Console();
		~Console();

		void AttachToStdOut();
		void Write(String const& sData);

	private:
		HANDLE m_hConsole;

		CLASS_NOCOPY(Console);
	};
};

#endif // _H_ROCK_CONSOLE