#ifndef _H_ROCK_STRINGBUILDER
#define _H_ROCK_STRINGBUILDER 1

#include "Rock_Types.h"
#include "Rock_Defines.h"
#include "Rock_String.h"

#include <deque>

namespace Rock {

	class ROCK_API StringBuilder {
	public:
		typedef std::deque<String> t_container;

		StringBuilder();
		StringBuilder(String const& s);

		StringBuilder& Append(String const& s);
		RBOOL operator==(StringBuilder const& sb) const;
		String ToString() const;

		INLINE RUINT GetLength() const {
			return m_nLength;
		}

		INLINE StringBuilder& AppendLine(String const& s) {
			Append(s);
			Append("\n");
			return *this;
		}

		INLINE StringBuilder& operator<<(String const& s) {
			return Append(s);
		}

		INLINE RBOOL operator!=(StringBuilder const& sb) const {
			return !(*this == sb);
		}

		INLINE RBOOL operator==(String const& s) const {
			return *this == StringBuilder(s);
		}

		INLINE RBOOL operator!=(String const& s) const {
			return !(*this == StringBuilder(s));
		}

		INLINE String operator*() const {
			return ToString();
		}

	private:
		t_container m_lData;
		RUINT m_nLength;
	};
};

#endif // _H_ROCK_STRINGBUILDER
