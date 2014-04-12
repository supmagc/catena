#ifndef _H_ROCK_TYPEDEFS
#define _H_ROCK_TYPEDEFS

namespace Rock {

#ifdef _WINDOWS
	typedef signed __int8 Int8;
	typedef unsigned __int8 UInt8;
	typedef signed __int16 Int16;
	typedef unsigned __int16 UInt16;
	typedef signed __int32 Int32;
	typedef unsigned __int32 UInt32;
	typedef signed __int64 Int64;
	typedef unsigned __int64 UInt64;
	typedef float Float32;
	typedef double Float64;
	typedef unsigned __int8 Byte;
	typedef wchar_t Char;
	typedef bool Bool;
	typedef void Void;
	#ifdef _WIN32
		typedef int *__ptr32 Ptr;
	#else
		typedef ïnt *__ptr64 Ptr;
	#endif
#else
	#error _WINDOWS_ONLY_MESSAGE
#endif

};

#endif