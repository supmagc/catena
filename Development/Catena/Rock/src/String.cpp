
#include "Rock_Std.h"
#include "Rock_String.h"
#include "Rock_Functions.h"

#include <cstring>
#include <cstdlib>
#include <wchar.h>
#include <sstream>
#include <string>

using namespace Rock;

String::String() : m_nLength(1), m_aData(NULL) {
    m_aData = new RCHAR[1];
    m_aData[0] = 0;
}

String::String(char const* str) : m_nLength(0), m_aData(NULL) {
    m_nLength = strlen(str) + 1;
    m_aData = new RCHAR[m_nLength];
    MultiByteToWideChar(CP_ACP, 0, str, m_nLength, m_aData, m_nLength);
}

String::String(RCHAR const* str) : m_nLength(0), m_aData(NULL) {
    m_nLength = wcslen(str) + 1;
    m_aData = new RCHAR[m_nLength];
    wcscpy_s(m_aData, m_nLength, str);
}

String::String(char const obj) : m_nLength(2), m_aData(NULL) {
    m_aData = new RCHAR[m_nLength];
    MultiByteToWideChar(CP_UTF8, 0, &obj, 1, m_aData, 1);
    m_aData[1] = 0;
}

String::String(RCHAR const obj) : m_nLength(2), m_aData(RNULL) {
    m_aData = new RCHAR[m_nLength];
    m_aData[0] = obj;
    m_aData[1] = 0;
}

String::String(String const& obj) : m_nLength(obj.m_nLength), m_aData(RNULL) {
    m_aData = new RCHAR[m_nLength];
    wcscpy_s(m_aData, m_nLength, obj.m_aData);
}

String::String(RINT8 const obj) : m_nLength(0), m_aData(NULL) {
    m_aData = new RCHAR[5];
    _itow_s(obj, m_aData, 5, 10);
    m_nLength = wcslen(m_aData) + 1;
}

String::String(RUINT8 const obj) : m_nLength(0), m_aData(NULL) {
    m_aData = new RCHAR[4];
    _itow_s(obj, m_aData, 4, 10);
    m_nLength = wcslen(m_aData) + 1;
}

String::String(RINT16 const obj) : m_nLength(0), m_aData(NULL) {
    m_aData = new RCHAR[7];
    _itow_s(obj, m_aData, 7, 10);
    m_nLength = wcslen(m_aData) + 1;
}

String::String(RUINT16 const obj) : m_nLength(0), m_aData(NULL) {
    m_aData = new RCHAR[6];
    _itow_s(obj, m_aData, 6, 10);
    m_nLength = wcslen(m_aData) + 1;
}

String::String(RINT32 const obj) : m_nLength(0), m_aData(NULL) {
    m_aData = new RCHAR[12];
    _itow_s(obj, m_aData, 12, 10);
    m_nLength = wcslen(m_aData) + 1;
}

String::String(RUINT32 const obj) : m_nLength(0), m_aData(NULL) {
    m_aData = new RCHAR[11];
    _ultow_s(obj, m_aData, 11, 10);
    m_nLength = wcslen(m_aData) + 1;
}

String::String(RINT64 const obj) : m_nLength(0), m_aData(NULL) {
    m_aData = new RCHAR[21];
    _i64tow_s(obj, m_aData, 21, 10);
    m_nLength = wcslen(m_aData) + 1;
}

String::String(RUINT64 const obj) : m_nLength(0), m_aData(NULL) {
    m_aData = new RCHAR[21];
    _ui64tow_s(obj, m_aData, 21, 10);
    m_nLength = wcslen(m_aData) + 1;
}

String::String(RFLOAT const obj) : m_nLength(0), m_aData(NULL) {
    char tmp[_CVTBUFSIZE];
    _gcvt_s(tmp, _CVTBUFSIZE, obj, RFLOAT_DIGITS);
    m_nLength = strlen(tmp) + 1;
    m_aData = new RCHAR[m_nLength];
    MultiByteToWideChar(CP_ACP, 0, tmp, m_nLength, m_aData, m_nLength);
}

String::String(RDOUBLE const obj) : m_nLength(0), m_aData(NULL) {
    char tmp[_CVTBUFSIZE];
    _gcvt_s(tmp, _CVTBUFSIZE, obj, RDOUBLE_DIGITS);
    m_nLength = strlen(tmp) + 1;
    m_aData = new RCHAR[m_nLength];
    MultiByteToWideChar(CP_ACP, 0, tmp, m_nLength, m_aData, m_nLength);
}

String::String(RBOOL const obj) : m_nLength(obj ? 2 : 1), m_aData(NULL) {
    m_aData = new RCHAR[m_nLength];
    if(obj) {
        m_aData[0] = L'1';
        m_aData[1] = 0;
    }
    else {
        m_aData[0] = 0;
    }
}

String::~String() {
    delete[] m_aData;
}

RINT8 String::ToInt8() const {
    return (RINT8)_wtoi(m_aData);
}

RUINT8 String::ToUInt8() const {
    return (RUINT8)_wtoi(m_aData);
}

RINT16 String::ToInt16() const {
    return (RINT16)_wtoi(m_aData);
}

RUINT16 String::ToUInt16() const {
    return (RUINT16)_wtoi(m_aData);
}

RINT32 String::ToInt32() const {
    return (RINT32)_wtoi(m_aData);
}

RUINT32 String::ToUInt32() const {
    return (RUINT32)_wcstoui64(m_aData, NULL, 10);
}

RINT64 String::ToInt64() const {
    return (RINT64)_wcstoi64(m_aData, NULL, 10);
}

RUINT64 String::ToUInt64() const {
    return (RUINT64)_wcstoui64(m_aData, NULL, 10);
}

RFLOAT String::ToFloat() const {
    return (RFLOAT)wcstod(m_aData, NULL);
}

RDOUBLE String::ToDouble() const {
    return (RDOUBLE)wcstod(m_aData, NULL);
}

RBOOL String::ToBool() const {
    return m_aData[0] != 0;
}

RUINT32 String::ToBytes(RBYTE* sBytes, RUINT nLength) const {
	if (nLength > m_nLength) {
		catMemZero(sBytes + m_nLength, nLength - m_nLength);
	}
	return WideCharToMultiByte(CP_ACP, 0, m_aData, m_nLength, sBytes, nLength, RNULL, RNULL);
}

RUINT32 const String::GetLength() const {
    return m_nLength - 1;
}

RCHAR const* String::GetData() const {
    return m_aData;
}

String String::SubString(RUINT32 nStart) const {
    if(nStart > GetLength()) return String();
    return String(m_aData + nStart);
}

String String::SubString(RUINT32 nStart, RUINT32 nLength) const {
	if (nStart + nLength >= GetLength()) {
		return SubString(nStart);
	}
    String tmp;
	if (nLength <= 0) {
		return tmp;
	}
	SAFE_DELETE_ARRAY(tmp.m_aData);
	tmp.m_nLength = nLength + 1;
	tmp.m_aData = new RCHAR[tmp.m_nLength];
	tmp.m_aData[tmp.m_nLength - 1] = 0;
	catMemCopy(m_aData + nStart, tmp.m_aData, nLength * RCHAR_SIZE);
    return tmp;
}

String String::ToUpper() const {
    String tmp = *this;
    for(RINT32 i=0 ; i<m_nLength ; ++i) tmp.m_aData[i] = towupper(tmp.m_aData[i]);
    return tmp;
}

String String::ToLower() const {
    String tmp = *this;
    for(RINT32 i=0 ; i<m_nLength ; ++i) tmp.m_aData[i] = towlower(tmp.m_aData[i]);
    return tmp;
}

String String::Trim() const {
    RUINT32 begin = 0;
    RUINT32 end = m_nLength - 1;
    while(iswspace(m_aData[begin]) && begin < end) ++begin;
    while(iswspace(m_aData[end-1]) && end > begin) --end;
	return SubString(begin, end - begin);
}

String& String::operator=(String const& str) {
    if(this != &str) {
        delete[] m_aData;
        m_nLength = str.m_nLength;
        m_aData = new RCHAR[m_nLength];
        wcscpy_s(m_aData, m_nLength, str.m_aData);
    }
    return *this;
}

String& String::operator+=(String const& str) {
    RCHAR* tmp = m_aData;
    m_nLength += str.GetLength();
    m_aData = new RCHAR[m_nLength];
    wcscpy_s(m_aData, m_nLength, tmp);
    wcscat_s(m_aData, m_nLength, str.m_aData);
    if(m_aData != str.m_aData) delete[] tmp;
    return *this;
}

String String::operator+(String const& str) const {
    String tmp = *this;
    return tmp += str;
}

bool String::operator==(String const& str) const {
    if(this == &str) return true;
    return wcscmp(m_aData, str.m_aData) == 0;
}

bool String::operator!=(String const& str) const {
    return !this->operator==(str);
}

RBOOL String::BeginsWith(String const& str) const {
    if(str.GetLength() > GetLength()) return false;
    for(RINT32 i=0 ; i<str.GetLength() ; ++i) if(m_aData[i] != str.m_aData[i]) return false;
    return true;
}

RBOOL String::EndsWith(String const& str) const {
    if(str.GetLength() > GetLength()) return false;
    for(RINT32 i=0 ; i<str.GetLength() ; ++i) if(m_aData[GetLength() - i] != str.m_aData[str.GetLength() - i]) return false;
    return true;
}

RINT32 String::IndexOf(String const& str) const {
    RINT32 nSourceIndex = 0;
    RINT32 nSearchIndex = 0;
    while(nSourceIndex < GetLength()) {
        if(m_aData[nSourceIndex++] != str.m_aData[nSearchIndex++]) {
            nSearchIndex = 0;
        }
        else if(nSearchIndex == str.GetLength()) {
            return nSourceIndex - str.GetLength();
        }
    }
    return -1;
}

String String::Replace(String const& search, String const& replace) const {
    String ret;
    RINT32 nSourceOffset = 0;
    RINT32 nSourceLength = 0;
    RINT32 nSearchLength = 0;
    while(nSourceOffset + nSourceLength < GetLength()) {
        if(m_aData[nSourceOffset + nSourceLength++] != search.m_aData[nSearchLength++]) {
            nSearchLength = 0;
        }
        else if(nSearchLength == search.GetLength()) {
            ret += SubString(nSourceOffset, nSourceLength - search.GetLength()) + replace;
            nSourceOffset += nSourceLength;
            nSourceLength = 0;
            nSearchLength = 0;
        }
    }
    return ret + SubString(nSourceOffset);
}

RCHAR const* String::operator*() const {
    return m_aData;
}

#define _STRING_APPEND(t) \
    String& String::operator=(t const& obj) {return operator=(String(obj));} \
    String& String::operator+=(t const& obj) {return operator+=(String(obj));} \
    RBOOL String::BeginsWith(t const& obj) const {return BeginsWith(String(obj));} \
    RBOOL String::EndsWith(t const& obj) const {return EndsWith(String(obj));} \
    RINT32 String::IndexOf(t const& obj) const {return IndexOf(String(obj));} \
    String String::Replace(t const& search, String const& replace) const {return Replace(String(search), replace);} \
    String String::Replace(String const& search, t const& replace) const {return Replace(search, String(replace));} \
    String String::Replace(t const& search, t const& replace) const {return Replace(String(search), String(replace));} \
        
    _STRING_APPEND(RCHAR);
    _STRING_APPEND(RBYTE);
    _STRING_APPEND(RCHAR const*);
    _STRING_APPEND(RBYTE const*);
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

#define _APPEND_STRING(t) \
    ROCK_API String Rock::operator+(t const& obj, String const& str) {return String(obj) + str;} \
    ROCK_API RBOOL Rock::operator==(t const& obj, String const& str) {return String(obj) == str;} \
    ROCK_API RBOOL Rock::operator!=(t const& obj, String const& str) {return String(obj) != str;} \
    ROCK_API String Rock::operator+(String const& str, t const& obj) {return str + String(obj);} \
    ROCK_API RBOOL Rock::operator==(String const& str, t const& obj) {return str == String(obj);} \
    ROCK_API RBOOL Rock::operator!=(String const& str, t const& obj) {return str != String(obj);} \

    _APPEND_STRING(RCHAR);
    _APPEND_STRING(RBYTE);
    _APPEND_STRING(RCHAR const*);
    _APPEND_STRING(RBYTE const*);
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

String String::Format(String const& str, va_list args) {
    return String::Format(str.m_aData, args);
}

String String::Format(RCHAR const* str, va_list args) {
    RUINT nLength = _vscwprintf(str, args) + 1;
	RCHAR* aBuffer = (RCHAR*)malloc(nLength * RCHAR_SIZE);
    vswprintf_s(aBuffer, nLength, str, args);
	String sReturn(aBuffer);
	SAFE_DELETE_ARRAY(aBuffer);
    return sReturn;
}

String String::Format(RBYTE const* str, va_list args) {
    RUINT nLength = _vscprintf(str, args) + 1;
    RBYTE* aBuffer = (char*)malloc(nLength);
    vsprintf_s(aBuffer, nLength, str, args);
    String sReturn = String(aBuffer);
    SAFE_DELETE_ARRAY(aBuffer);
    return sReturn;
}

String String::Format(String const str, ...) {
    va_list args;
    va_start(args, str);
    String sReturn = String::Format(str.m_aData, args);
    va_end(args);
    return sReturn;
}

String String::Format(RCHAR const* str, ...) {
    va_list args;
    va_start(args, str);
    String sReturn = String::Format(str, args);
    va_end(args);
    return sReturn;
}

String String::Format(RBYTE const* str, ...) {
    va_list args;
    va_start(args, str);
    String sReturn = String::Format(str, args);
    va_end(args);
    return sReturn;
}

ROCK_API std::ostream& Rock::operator<<(std::ostream & stream, String const& str) {
	RUINT nLength = str.GetLength() + 1;
	RBYTE* aBuffer = (RBYTE*)catMemAlloc(nLength);
	str.ToBytes(aBuffer, nLength);
    stream << aBuffer;
	SAFE_DELETE_ARRAY(aBuffer);
    return stream;
}

ROCK_API std::wostream& Rock::operator<<(std::wostream & stream, String const& str) {
    stream << str.GetData();
    return stream;
}

ROCK_API std::istream& Rock::operator>>(std::istream & stream, String & str) {
    std::string s;
    stream >> s;
    str = String(s.c_str());
    return stream;
}

ROCK_API std::wistream& Rock::operator>>(std::wistream & stream, String & str) {
    std::wstring s;
    stream >> s;
    str = String(s.c_str());
    return stream;
}
