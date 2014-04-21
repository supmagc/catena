#ifndef _H_ROCK_EXCEPTIONS
#define _H_ROCK_EXCEPTIONS

#include "Rock_String.h"
#include "Rock_Exception.h"
#include "Rock_Defines.h"

namespace Rock {

    class DLL_EXPORT Exception {
    public:
        Exception(char const* sMessage) : m_sMessage(Str(sMessage)) {}
        Exception(RCHAR const* sMessage) : m_sMessage(Str(sMessage)) {}
        Exception(String const& sMessage) : m_sMessage(sMessage) {}
        virtual ~Exception() {}
        String const& GetMessage() const {return m_sMessage;}

    private:
        String const m_sMessage;
    };
};

#define EXCEPTION(n) class DLL_EXPORT n##Exception : public Rock::Exception { \
public: \
    n##Exception(char const* sMessage) : Rock::Exception(Rock::String(sMessage)) { } \
    n##Exception(Rock::RCHAR const* sMessage) : Rock::Exception(Rock::String(sMessage)) { } \
    n##Exception(Rock::RCHAR const& sMessage) : Rock::Exception(sMessage) { } \
    virtual ~n##Exception() {} \
}

#endif
