#ifndef _H_ROCK_DEFINES
#define _H_ROCK_DEFINES

#if !defined(_UNICODE)
    #error Rock is considered to always require unicode support.
#endif

#if defined(DEBUG) && !defined(_DEBUG)
    #define _DEBUG
#endif

#if defined(_ASSERT) && defined(NASSERT)
    #error You shoulnd't run this code when both _ASSERT and NASSERT are defined.
#endif

#if defined(_DEBUG) && defined(NDEBUG)
    #error You shoulnd't run this code when both _DEBUG and NDEBUG are defined.
#endif

#if !defined(_WINDOWS) && (defined(_WIN32) || defined(_WIN64))
    #define _WINDOWS
#endif

#define _ERROR_WINDOWS_ONLY This code is only implemented to compile under windows.

#define BREAK __asm { int 3 }
#define SAFE_RELEASE(p) if(p != NULL) {p->Release(); p=NULL;}
#define SAFE_rELEASE(p) if(p != NULL) {p->release(); p=NULL;}
#define SAFE_DELETE(p) if(p != NULL) {delete p; p=NULL;}
#define SAFE_DELETE_ARRAY(p) if(p != NULL) {delete[] p; p=NULL;}
#define FLAG_HAS_ALL(n, f) (((n)&(f))==(f))
#define FLAG_HAS_NOT(n, f) (((n)&(f))==0)
#define FLAG_HAS_ONLY(n, f) ((n)==(f))
#define FLAG_HAS_ANY(n, f) (((n)&(f))>0)
#define FLAG_HAS(n, f) FLAG_HAS_ALL(n, f)
#define FLAG_SET(n, f) (n|=(f))
#define FLAG_CLEAR(n, f) (n&=~(f))
#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)
#define ROCK_API DLL_EXPORT

#endif // _H_ROCK_DEFINES