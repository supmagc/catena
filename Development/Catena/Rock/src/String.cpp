
#include "RockStd.h"
#include "RockString.h"

#include <cstring>
#include <cstdlib>
#include <wchar.h>
#include <sstream>
#include <string>

using namespace Rock;

String::String() : m_nLength(1), m_aData(NULL) {
	m_aData = new Char[1];
	m_aData[0] = 0;
}

String::String(char const* str) : m_nLength(0), m_aData(NULL) {
	m_nLength = strlen(str) + 1;
	m_aData = new Char[m_nLength];
	MultiByteToWideChar(CP_UTF8, 0, str, m_nLength, m_aData, m_nLength);
}

String::String(Char const* str) : m_nLength(0), m_aData(NULL) {
	m_nLength = wcslen(str) + 1;
	m_aData = new Char[m_nLength];
	wcscpy_s(m_aData, m_nLength, str);
}

String::String(char const obj) : m_nLength(2), m_aData(NULL) {
	m_aData = new Char[m_nLength];
	MultiByteToWideChar(CP_UTF8, 0, &obj, 1, m_aData, 1);
	m_aData[1] = 0;
}

String::String(Char const obj) : m_nLength(2), m_aData(NULL) {
	m_aData = new Char[m_nLength];
	m_aData[0] = obj;
	m_aData[1] = 0;
}

String::String(String const& obj) : m_nLength(0), m_aData(NULL) {
	m_nLength = obj.m_nLength;
	m_aData = new Char[m_nLength];
	wcscpy_s(m_aData, m_nLength, obj.m_aData);
}

String::String(Int8 const obj) : m_nLength(0), m_aData(NULL) {
	m_aData = new Char[5];
	_itow_s(obj, m_aData, 5, 10);
	m_nLength = wcslen(m_aData) + 1;
}

String::String(UInt8 const obj) : m_nLength(0), m_aData(NULL) {
	m_aData = new Char[4];
	_itow_s(obj, m_aData, 4, 10);
	m_nLength = wcslen(m_aData) + 1;
}

String::String(Int16 const obj) : m_nLength(0), m_aData(NULL) {
	m_aData = new Char[7];
	_itow_s(obj, m_aData, 7, 10);
	m_nLength = wcslen(m_aData) + 1;
}

String::String(UInt16 const obj) : m_nLength(0), m_aData(NULL) {
	m_aData = new Char[6];
	_itow_s(obj, m_aData, 6, 10);
	m_nLength = wcslen(m_aData) + 1;
}

String::String(Int32 const obj) : m_nLength(0), m_aData(NULL) {
	m_aData = new Char[12];
	_itow_s(obj, m_aData, 12, 10);
	m_nLength = wcslen(m_aData) + 1;
}

String::String(UInt32 const obj) : m_nLength(0), m_aData(NULL) {
	m_aData = new Char[11];
	_ultow_s(obj, m_aData, 11, 10);
	m_nLength = wcslen(m_aData) + 1;
}

String::String(Int64 const obj) : m_nLength(0), m_aData(NULL) {
	m_aData = new Char[21];
	_i64tow_s(obj, m_aData, 21, 10);
	m_nLength = wcslen(m_aData) + 1;
}

String::String(UInt64 const obj) : m_nLength(0), m_aData(NULL) {
	m_aData = new Char[21];
	_ui64tow_s(obj, m_aData, 21, 10);
	m_nLength = wcslen(m_aData) + 1;
}

String::String(Float32 const obj) : m_nLength(0), m_aData(NULL) {
	char tmp[_CVTBUFSIZE];
	_gcvt_s(tmp, _CVTBUFSIZE, obj, 40);
	m_nLength = strlen(tmp) + 1;
	m_aData = new Char[m_nLength];
	MultiByteToWideChar(CP_UTF8, 0, tmp, m_nLength, m_aData, m_nLength);
}

String::String(Float64 const obj) : m_nLength(0), m_aData(NULL) {
	char tmp[_CVTBUFSIZE];
	_gcvt_s(tmp, _CVTBUFSIZE, obj, 40);
	m_nLength = strlen(tmp) + 1;
	m_aData = new Char[m_nLength];
	MultiByteToWideChar(CP_UTF8, 0, tmp, m_nLength, m_aData, m_nLength);

}

String::String(Bool const obj) : m_nLength(obj ? 2 : 1), m_aData(NULL) {
	m_aData = new Char[m_nLength];
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

Int8 String::ToInt8() const {
	return (Int8)_wtoi(m_aData);
}

UInt8 String::ToUInt8() const {
	return (UInt8)_wtoi(m_aData);
}

Int16 String::ToInt16() const {
	return (Int16)_wtoi(m_aData);
}

UInt16 String::ToUInt16() const {
	return (UInt16)_wtoi(m_aData);
}

Int32 String::ToInt32() const {
	return (Int32)_wtoi(m_aData);
}

UInt32 String::ToUInt32() const {
	return (UInt32)_wcstoui64(m_aData, NULL, 10);
}

Int64 String::ToInt64() const {
	return (Int64)_wcstoi64(m_aData, NULL, 10);
}

UInt64 String::ToUInt64() const {
	return (UInt64)_wcstoui64(m_aData, NULL, 10);
}

Float32 String::ToFloat32() const {
	return (Float32)wcstod(m_aData, NULL);
}

Float64 String::ToFloat64() const {
	return (Float64)wcstod(m_aData, NULL);
}

Bool String::ToBool() const {
	return m_aData[0] != 0;
}

Int32 const String::GetLength() const {
	return m_nLength - 1;
}

Char const* String::GetData() const {
	return m_aData;
}

String String::SubString(Int32 nStart) const {
	if(nStart < 0) nStart = 0;
	if(nStart > GetLength()) return String();
	return String(m_aData + nStart);
}

String String::SubString(Int32 nStart, Int32 nLength) const {
	if(nStart < 0) nStart = 0;
	if(nStart + nLength > GetLength()) return SubString(nStart);
	String tmp = *this;
	tmp.m_aData[nStart + nLength] = 0;
	return String(tmp.m_aData + nStart);
}

String String::ToUpper() const {
	String tmp = *this;
	for(Int32 i=0 ; i<m_nLength ; ++i) tmp.m_aData[i] = towupper(tmp.m_aData[i]);
	return tmp;
}

String String::ToLower() const {
	String tmp = *this;
	for(Int32 i=0 ; i<m_nLength ; ++i) tmp.m_aData[i] = towlower(tmp.m_aData[i]);
	return tmp;
}

String String::Trim() const {
	Int32 begin = 0;
	Int32 end = GetLength() - 1;
	while((m_aData[begin] == L' ' || m_aData[begin] == L'\r' || m_aData[begin] == L'\n') && m_aData[begin] != 0) ++begin;
	while((m_aData[end] == L' ' || m_aData[end] == L'\r' || m_aData[end] == L'\n') && end > begin) --end;
	return SubString(begin, end - begin + 1);
}

String& String::operator=(String const& str) {
	if(this != &str) {
		delete[] m_aData;
		m_nLength = str.m_nLength;
		m_aData = new Char[m_nLength];
		wcscpy_s(m_aData, m_nLength, str.m_aData);
	}
	return *this;
}

String& String::operator+=(String const& str) {
	Char* tmp = m_aData;
	m_nLength += str.GetLength();
	m_aData = new Char[m_nLength];
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

Bool String::BeginsWith(String const& str) const {
	if(str.GetLength() > GetLength()) return false;
	for(Int32 i=0 ; i<str.GetLength() ; ++i) if(m_aData[i] != str.m_aData[i]) return false;
	return true;
}

Bool String::EndsWith(String const& str) const {
	if(str.GetLength() > GetLength()) return false;
	for(Int32 i=0 ; i<str.GetLength() ; ++i) if(m_aData[GetLength() - i] != str.m_aData[str.GetLength() - i]) return false;
	return true;
}

Int32 String::IndexOf(String const& str) const {
	Int32 nSourceIndex = 0;
	Int32 nSearchIndex = 0;
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
	Int32 nSourceOffset = 0;
	Int32 nSourceLength = 0;
	Int32 nSearchLength = 0;
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
