#ifndef _H_ROCK_DEFINES
#define _H_ROCK_DEFINES

#if !defined(_UNICODE)
    #error Rock is considered to always require unicode support.
#endif

#if defined(_ASSERT) && defined(NASSERT)
    #error You shoulnd't run this code when both _ASSERT and NASSERT are defined.
#endif

#if defined(_DEBUG) && defined(NDEBUG)
    #error You shoulnd't run this code when both _DEBUG and NDEBUG are defined.
#endif

#if !defined(_WINDOWS) && (defined(_WIN32) || defined(_WIN64))
    #define _WINDOWS 1
#endif

#define _ERROR_WINDOWS_ONLY This code is only implemented to compile under windows.

// Debug defines
#ifdef _WINDOWS
    #define BREAK_ALWAYS _CrtDbgBreak();
    #ifdef _DEBUG
        #define BREAK_DEBUG _CrtDbgBreak()
    #else
        #define BREAK_DEBUG
    #endif
#else
    #define BREAK_ALWAYS
    #define BREAK_DEBUG
#endif

// Inline defines
#ifdef _WINDOWS
    #define INLINE __forceinline
#else
    #define INLINE always_inline
#endif

// Math defines
#define E        2.71828182845904523536
#define PI       3.14159265358979323846
#define DEG2RAD  (PI / 180.0)
#define RAD2DEG  (180.0 / PI)

// Delete/release defines
#define SAFE_RELEASE(p) if(p != NULL) {p->Release(); p=NULL;}
#define SAFE_rELEASE(p) if(p != NULL) {p->release(); p=NULL;}
#define SAFE_DELETE(p) if(p != NULL) {delete p; p=NULL;}
#define SAFE_DELETE_ARRAY(p) if(p != NULL) {delete[] p; p=NULL;}

// Flag defines
#define FLAG_HAS_ALL(n, f) (((n)&(f))==(f))
#define FLAG_HAS_NOT(n, f) (((n)&(f))==0)
#define FLAG_HAS_ONLY(n, f) ((n)==(f))
#define FLAG_HAS_ANY(n, f) (((n)&(f))>0)
#define FLAG_HAS(n, f) FLAG_HAS_ALL(n, f)
#define FLAG_SET(n, f) (n|=(f))
#define FLAG_CLEAR(n, f) (n&=~(f))

// DLL defines
#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)

// Pimpl defines
#define PIMPL_DECL(cls) struct cls##Impl; cls##Impl* m_pImpl
#define PIMPL_INIT(cls) m_pImpl = new cls##Impl; catMemZero(m_pImpl, sizeof(cls##Impl))
#define PIMPL_MAKE(ns, cls) struct ns##::##cls##::##cls##Impl
#define PIMPL_DELETE() SAFE_DELETE(m_pImpl)
#define PIMPL (*m_pImpl)

// Class defines
#define CLASS_NOCOPY(cls) cls##(##cls const&); cls##& operator=(##cls const&)

// Text defines
#define RTXT(txt) L##txt

// Settings paradigm
#define SETTINGS(func) o##func##Settings
#define SETTINGS_DECL(func, call) struct call func##Settings
#define SETTINGS_INIT(ns, func) ns::func##Settings o##func##Settings = ns::func##Settings(); catMemZero(&o##func##Settings, sizeof(ns::func##Settings))
#define SETTINGS_BOX(func) (RCBOX) &o##func##Settings
#define SETTINGS_PARAM(func) RCBOX p##func##SettingsBoxed
#define SETTINGS_UNBOX(func) func##Settings const* p##func##Settings = reinterpret_cast<func##Settings const*>(p##func##SettingsBoxed); CHECK_NOTNULL(p##func##Settings)

// Default settings stuff
#define DEFAULT_ALIGNMENT 8
#define DEFAULT_ALLOCATOR Rock::HeapAllocator::Boxed
#define DEFAULT_ARRAY_CAPACITY 32
#define DEFAULT_ARRAY_BLOCKSIZE 0

// Rock specific defines
#if defined(ROCK_EXPORTS)
    #define ROCK_API DLL_EXPORT
#elif defined(ROCK_IMPORTS)
    #define ROCK_API DLL_IMPORT
#else
    #define ROCK_API 
#endif

#endif // _H_ROCK_DEFINES