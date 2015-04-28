
ROCK_API INLINE RBOX catMemAlloc(RUINT nSize, RUINT nAlignment) {
    return malloc(nSize);
}

ROCK_API INLINE RBOX catMemRealloc(RBOX pAdress, RUINT nSize, RUINT nAlignment) {
    return realloc(pAdress, nSize);
}

ROCK_API INLINE void catMemFree(RBOX pAdress) {
    free(pAdress);
}

ROCK_API INLINE void catMemCopy(RCBOX pSrc, RBOX pDst, RUINT nSize) {
    memcpy_s(pDst, nSize, pSrc, nSize);
}

ROCK_API INLINE void catMemMove(RCBOX pSrc, RBOX pDst, RUINT nSize) {
    memmove_s(pDst, nSize, pSrc, nSize);
}

ROCK_API INLINE void catMemZero(RBOX pAdress, RUINT nSize) {
    memset(pAdress, 0, nSize);
}

ROCK_API INLINE void catMemSet(RBOX pAdress, RINT nValue, RUINT nSize) {
    memset(pAdress, nValue, nSize);
}

ROCK_API INLINE void catMemSwap(RBOX p0, RBOX p1, RUINT nLength) {
    if(p0 == p1) return;
}

template<typename Element, RUINT ElementSize = sizeof(Element)>
ROCK_API INLINE void catMemSwap(Element& m0, Element& m1) {
    if(&m0 == &m1) return;
    Element mTmp;
    catMemCopy(&m0, &mTmp, ElementSize);
    catMemCopy(&m1, &m0, ElementSize);
    catMemCopy(&mTmp, &m0, ElementSize);
}

ROCK_API INLINE void catSleep(RDOUBLE nDuration) {
    Sleep((RINT64)(nDuration * 1000.0));
}

ROCK_API INLINE RBOOL catIsDebug() {
#if defined(_DEBUG)
    return true;
#else
    return false;
#endif
}

ROCK_API INLINE RBOOL catIsRelease() {
#if !defined(_DEBUG) && !defined(_PUBLISH)
    return true;
#else
    return false;
#endif
}

ROCK_API INLINE RBOOL catIsPublish() {
#if defined(_PUBLISH)
    return true;
#else
    return false;
#endif
}
