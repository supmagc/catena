#ifndef _H_ROCK_DEFINES
#define _H_ROCK_DEFINES

#define BREAK __asm { int 3 }
#define SAFE_RELEASE(p) if(p != NULL) {p->Release(); p=NULL;}
#define SAFE_rELEASE(p) if(p != NULL) {p->release(); p=NULL;}
#define SAFE_DELETE(p) if(p != NULL) {delete p; p=NULL;}
#define SAFE_DELETE_ARRAY(p) if(p != NULL) {delete[] p; p=NULL;}
#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)
#define FLAG_HAS_ALL(n, f) (((n)&(f))==(f))
#define FLAG_HAS_NOT(n, f) (((n)&(f))==0)
#define FLAG_HAS_ONLY(n, f) ((n)==(f))
#define FLAG_HAS_ANY(n, f) (((n)&(f))>0)
#define FLAG_HAS(n, f) FLAG_HAS_ALL(n, f)
#define FLAG_SET(n, f) (n|=(f))
#define FLAG_CLEAR(n, f) (n&=~(f))

#endif