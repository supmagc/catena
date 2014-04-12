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

#include "TypeDefs.h"
#include <iostream>

namespace Rock {

	class DLL_EXPORT String {
	public:
		String();
		String(char const* str);
		String(Char const* str);
		String(char const str);
		String(Char const str);
		String(String const& obj);
		String(Int8 const obj);
		String(UInt8 const obj);
		String(Int16 const obj);
		String(UInt16 const obj);
		String(Int32 const obj);
		String(UInt32 const obj);
		String(Int64 const obj);
		String(UInt64 const obj);
		String(Float32 const obj);
		String(Float64 const obj);
		String(Bool const obj);
		~String();

		Int8 ToInt8() const;
		UInt8 ToUInt8() const;
		Int16 ToInt16() const;
		UInt16 ToUInt16() const;
		Int32 ToInt32() const;
		UInt32 ToUInt32() const;
		Int64 ToInt64() const;
		UInt64 ToUInt64() const;
		Float32 ToFloat32() const;
		Float64 ToFloat64() const;
		Bool ToBool() const;

		Int32 const GetLength() const;
		Char const* GetData() const;
		String SubString(Int32 nStart) const;
		String SubString(Int32 nStart, Int32 nLength) const;
		String ToUpper() const;
		String ToLower() const;
		String Trim() const;
		String& operator=(String const& str);
		String& operator+=(String const& str);
		String operator+(String const& str) const;
		Bool operator==(String const& str) const;
		Bool operator!=(String const& str) const;
		Bool BeginsWith(String const& str) const;
		Bool EndsWith(String const& str) const;
		Int32 IndexOf(String const& str) const;
		String Replace(String const& search, String const& replace) const;

#define _STRING_APPEND(t) \
		String& operator=(t const& obj) {return operator=(String(obj));} \
		String& operator+=(t const& obj) {return operator+=(String(obj));} \
		String operator+(t const& obj) const {return operator+(String(obj));} \
		Bool operator==(t const& obj) const {return operator==(String(obj));} \
		Bool operator!=(t const& obj) const {return operator!=(String(obj));} \
		Bool BeginsWith(t const& obj) const {return BeginsWith(String(obj));} \
		Bool EndsWith(t const& obj) const {return EndsWith(String(obj));} \
		Int32 IndexOf(t const& obj) const {return IndexOf(String(obj));} \
		String Replace(t const& search, String const& replace) const {return Replace(String(search), replace);} \
		String Replace(String const& search, t const& replace) const {return Replace(search, String(replace));} \
		String Replace(t const& search, t const& replace) const {return Replace(String(search), String(replace));} \
		

		_STRING_APPEND(Char);
		_STRING_APPEND(char);
		_STRING_APPEND(Char const*);
		_STRING_APPEND(char const*);
		_STRING_APPEND(Int8);
		_STRING_APPEND(UInt8);
		_STRING_APPEND(Int16);
		_STRING_APPEND(UInt16);
		_STRING_APPEND(Int32);
		_STRING_APPEND(UInt32);
		_STRING_APPEND(Int64);
		_STRING_APPEND(UInt64);
		_STRING_APPEND(Float32);
		_STRING_APPEND(Float64);
		_STRING_APPEND(Bool);
#undef _STRING_APPEND

	private:
		Int32 m_nLength;
		Char * m_aData;
	};

	DLL_EXPORT std::ostream& operator<<(std::ostream & stream, String const& str);
	DLL_EXPORT std::wostream& operator<<(std::wostream & stream, String const& str);
	DLL_EXPORT std::istream& operator>>(std::istream & stream, String & str);
	DLL_EXPORT std::wistream& operator>>(std::wistream & stream, String & str);

	typedef String Str;
};

#endif