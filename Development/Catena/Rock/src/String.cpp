
#include "Rock_Std.h"
#include "Rock_String.h"

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
	MultiByteToWideChar(CP_UTF8, 0, str, m_nLength, m_aData, m_nLength);
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

String::String(RCHAR const obj) : m_nLength(2), m_aData(NULL) {
	m_aData = new RCHAR[m_nLength];
	m_aData[0] = obj;
	m_aData[1] = 0;
}

String::String(String const& obj) : m_nLength(0), m_aData(NULL) {
	m_nLength = obj.m_nLength;
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

String::String(RFLOAT32 const obj) : m_nLength(0), m_aData(NULL) {
	char tmp[_CVTBUFSIZE];
	_gcvt_s(tmp, _CVTBUFSIZE, obj, 40);
	m_nLength = strlen(tmp) + 1;
	m_aData = new RCHAR[m_nLength];
	MultiByteToWideChar(CP_UTF8, 0, tmp, m_nLength, m_aData, m_nLength);
}

String::String(RFLOAT64 const obj) : m_nLength(0), m_aData(NULL) {
	char tmp[_CVTBUFSIZE];
	_gcvt_s(tmp, _CVTBUFSIZE, obj, 40);
	m_nLength = strlen(tmp) + 1;
	m_aData = new RCHAR[m_nLength];
	MultiByteToWideChar(CP_UTF8, 0, tmp, m_nLength, m_aData, m_nLength);

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

RINT32 const String::GetLength() const {
	return m_nLength - 1;
}

RCHAR const* String::GetData() const {
	return m_aData;
}

String String::SubString(RINT32 nStart) const {
	if(nStart < 0) nStart = 0;
	if(nStart > GetLength()) return String();
	return String(m_aData + nStart);
}

String String::SubString(RINT32 nStart, RINT32 nLength) const {
	if(nStart < 0) nStart = 0;
	if(nStart + nLength > GetLength()) return SubString(nStart);
	String tmp = *this;
	tmp.m_aData[nStart + nLength] = 0;
	return String(tmp.m_aData + nStart);
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
	RINT32 begin = 0;
	RINT32 end = GetLength() - 1;
	while((m_aData[begin] == L' ' || m_aData[begin] == L'\r' || m_aData[begin] == L'\n') && m_aData[begin] != 0) ++begin;
	while((m_aData[end] == L' ' || m_aData[end] == L'\r' || m_aData[end] == L'\n') && end > begin) --end;
	return SubString(begin, end - begin + 1);
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
			return nSourceIndex;
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
			ret += SubString(nSourceOffset, nSourceLength - 1) + replace;
			nSourceOffset += nSourceLength;
			nSourceLength = 0;
			nSearchLength = 0;
		}
	}
	return ret + SubString(nSourceOffset);
}

ROCK_API std::ostream& Rock::operator<<(std::ostream & stream, String const& str) {
	stream << str.GetData();
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
