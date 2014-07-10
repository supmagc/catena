
ROCK_API FORCEINLINE RBOX catMemAlloc(RUINT nSize, RUINT nAlignment) {
    return malloc(nSize);
}

ROCK_API FORCEINLINE RBOX catMemRealloc(RBOX pAdress, RUINT nSize, RUINT nAlignment) {
    return realloc(pAdress, nSize);
}

ROCK_API FORCEINLINE void catMemFree(RBOX pAdress) {
    free(pAdress);
}

ROCK_API FORCEINLINE void catMemCopy(RCBOX pSrc, RBOX pDst, RUINT nSize) {
    memcpy_s(pDst, nSize, pSrc, nSize);
}

ROCK_API FORCEINLINE void catMemMove(RCBOX pSrc, RBOX pDst, RUINT nSize) {
    memmove_s(pDst, nSize, pSrc, nSize);
}

ROCK_API FORCEINLINE void catMemZero(RBOX pAdress, RUINT nSize) {
    memset(pAdress, 0, nSize);
}

ROCK_API FORCEINLINE void catMemSet(RBOX pAdress, RINT nValue, RUINT nSize) {
    memset(pAdress, nValue, nSize);
}

template<typename Element, RUINT ElementSize = sizeof(Element)>
ROCK_API FORCEINLINE void catSwap(Element& m0, Element& m1) {
    if(&m0 == &m1) return;
    Element mTmp;
    catMemCopy(&m0, &mTmp, ElementSize);
    catMemCopy(&m1, &m0, ElementSize);
    catMemCopy(&mTmp, &m0, ElementSize);
}

ROCK_API FORCEINLINE void catSleep(RDOUBLE nDuration) {
    Sleep((RINT64)(nDuration * 1000.0));
}

ROCK_API FORCEINLINE RBOOL catIsDebug() {
#if defined(_DEBUG)
    return true;
#else
    return false;
#endif
}

ROCK_API FORCEINLINE RBOOL catIsRelease() {
#if !defined(_DEBUG) && !defined(_PUBLISH)
    return true;
#else
    return false;
#endif
}

ROCK_API FORCEINLINE RBOOL catIsPublish() {
#if defined(_PUBLISH)
    return true;
#else
    return false;
#endif
}
