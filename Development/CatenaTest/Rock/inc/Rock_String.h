/**
 * Custom made string class
 *
 * Only works with wchar_t characters to force the usage of unicode.
 * It is however still possible to easily convert between ascii and unicode
 * by using the appropriate constructor.
 *
 * @author Voet Jelle - ToMo-design.be
 * @version 1.0.0 RC1
**/

#ifndef _H_ROCK_STRING
#define _H_ROCK_STRING

#include "Rock_Types.h"
#include "Rock_Defines.h"

namespace Rock {

    class ROCK_API String {
    public:
        String();
        String(char const* str);
        String(RCHAR const* str);
        String(char const str);
        String(RCHAR const str);
        String(String const& obj);
        String(RINT8 const obj);
        String(RUINT8 const obj);
        String(RINT16 const obj);
        String(RUINT16 const obj);
        String(RINT32 const obj);
        String(RUINT32 const obj);
        String(RINT64 const obj);
        String(RUINT64 const obj);
        String(RFLOAT const obj);
        String(RDOUBLE const obj);
        String(RBOOL const obj);
        ~String();

        RINT8 ToInt8() const;
        RUINT8 ToUInt8() const;
        RINT16 ToInt16() const;
        RUINT16 ToUInt16() const;
        RINT32 ToInt32() const;
        RUINT32 ToUInt32() const;
        RINT64 ToInt64() const;
        RUINT64 ToUInt64() const;
        RFLOAT ToFloat() const;
        RDOUBLE ToDouble() const;
        RBOOL ToBool() const;

        RINT32 const GetLength() const;
        RCHAR const* GetData() const;
        String SubString(RINT32 nStart) const;
        String SubString(RINT32 nStart, RINT32 nLength) const;
        String ToUpper() const;
        String ToLower() const;
        String Trim() const;
        String& operator=(String const& str);
        String& operator+=(String const& str);
        String operator+(String const& str) const;
        RBOOL operator==(String const& str) const;
        RBOOL operator!=(String const& str) const;
        RBOOL BeginsWith(String const& str) const;
        RBOOL EndsWith(String const& str) const;
        RINT32 IndexOf(String const& str) const;
        String Replace(String const& search, String const& replace) const;

#define _STRING_APPEND(t) \
        String& operator=(t const& obj); \
        String& operator+=(t const& obj); \
        String operator+(t const& obj) const; \
        RBOOL operator==(t const& obj) const; \
        RBOOL operator!=(t const& obj) const; \
        RBOOL BeginsWith(t const& obj) const; \
        RBOOL EndsWith(t const& obj) const; \
        RINT32 IndexOf(t const& obj) const; \
        String Replace(t const& search, String const& replace) const; \
        String Replace(String const& search, t const& replace) const; \
        String Replace(t const& search, t const& replace) const; \
        
        _STRING_APPEND(RCHAR);
        _STRING_APPEND(char);
        _STRING_APPEND(RCHAR const*);
        _STRING_APPEND(char const*);
        _STRING_APPEND(RINT8);
        _STRING_APPEND(RUINT8);
        _STRING_APPEND(RINT16);
        _STRING_APPEND(RUINT16);
        _STRING_APPEND(RINT32);
        _STRING_APPEND(RUINT32);
        _STRING_APPEND(RINT64);
        _STRING_APPEND(RUINT64);
        _STRING_APPEND(RFLOAT);
        _STRING_APPEND(RDOUBLE);
        _STRING_APPEND(RBOOL);
#undef _STRING_APPEND

    private:
        RINT32 m_nLength;
        RCHAR* m_aData;
    };

#define _APPEND_STRING(t) \
    ROCK_API String operator+(t const& obj, String const& str); \

    _APPEND_STRING(RCHAR);
    _APPEND_STRING(char);
    _APPEND_STRING(RCHAR const*);
    _APPEND_STRING(char const*);
    _APPEND_STRING(RINT8);
    _APPEND_STRING(RUINT8);
    _APPEND_STRING(RINT16);
    _APPEND_STRING(RUINT16);
    _APPEND_STRING(RINT32);
    _APPEND_STRING(RUINT32);
    _APPEND_STRING(RINT64);
    _APPEND_STRING(RUINT64);
    _APPEND_STRING(RFLOAT);
    _APPEND_STRING(RDOUBLE);
    _APPEND_STRING(RBOOL);
#undef _APPEND_STRING

    ROCK_API std::ostream& operator<<(std::ostream & stream, String const& str);
    ROCK_API std::wostream& operator<<(std::wostream & stream, String const& str);
    ROCK_API std::istream& operator>>(std::istream & stream, String & str);
    ROCK_API std::wistream& operator>>(std::wistream & stream, String & str);

    typedef String RString;
    typedef String Str;
    typedef Str RStr;
};

#endif
