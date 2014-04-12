#ifndef _H_ROCK_EXCEPTIONS
#define _H_ROCK_EXCEPTIONS

#include "Str.h"

namespace Rock {
	class DLL_EXPORT Exception {
	public:
		Exception(char const* sMessage) : m_sMessage(Str(sMessage)) {}
		Exception(Char const* sMessage) : m_sMessage(Str(sMessage)) {}
		Exception(Str const& sMessage) : m_sMessage(sMessage) {}
		virtual ~Exception() {}
		Str const& GetMessage() const {return m_sMessage;}

	private:
		Str const m_sMessage;
	};
};

#define EXCEPTION(n) class DLL_EXPORT n##Exception : public Rock::Exception { \
public: \
	n##Exception(char const* sMessage) : Rock::Exception(Rock::Str(sMessage)) { } \
	n##Exception(Rock::Char const* sMessage) : Rock::Exception(Rock::Str(sMessage)) { } \
	n##Exception(Rock::Str const& sMessage) : Rock::Exception(sMessage) { } \
	virtual ~n##Exception() {} \
}

#endif