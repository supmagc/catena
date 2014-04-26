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

// Debug defines
#define BREAK __asm { int 3 }

// Helper defines
#define ZERO(dest, length) memset((dest), 0, (length))

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
#define PIMPL_INIT(cls) m_pImpl = new cls##Impl; ZERO(m_pImpl, sizeof(cls##Impl))
#define PIMPL_MAKE(nsp, cls) struct nsp##::##cls##::##cls##Impl
#define PIMPL_DELETE() SAFE_DELETE(m_pImpl)
#define PIMPL (*m_pImpl)

// Rock specific defines
#define ROCK_API DLL_EXPORT

#endif // _H_ROCK_DEFINES