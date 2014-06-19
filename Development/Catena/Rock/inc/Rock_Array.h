#ifndef _H_ROCK_ARRAY
#define _H_ROCK_ARRAY 1

#include "Rock_Defines.h"
#include "Rock_Types.h"
#include "Rock_Assert.h"

namespace Rock {

    template<typename T>
    class ROCK_API Array {
    public:
        Array(RUINT nCapacity, RUINT nBlockSize) : m_nLength(0), m_nCapacity(nCapacity), m_nBlockSize(nBlockSize) {
            m_aData = new T[m_nCapacity];
        }

        Array(Array<T> const& oArray) : m_nLength(oArray.m_nLength), m_nCapacity(oArray.m_nCapacity), m_nBlockSize(oArray.m_nBlockSize) {
            m_aData = new T[m_nCapacity];
            COPY(oArray.m_aData, m_aData, m_nLength * sizeof(T));
        }

        Array(T* aArray, RUINT nLength, RUINT nBlockSize) : m_nLength(nLength), m_nCapacity(nCapacity), m_nBlockSize(nBlockSize) {
            m_aData = new T[m_nCapacity];
            COPY(oArray.m_aData, aArray, m_nLength * sizeof(T));
        }

        ~Array() {
            SAFE_DELETE_ARRAY(m_aData);
        }

        FORCEINLINE void Push(T mElement) {
            if(m_nLength >= m_nCapacity) {
                Increase(m_nBlockSize);
            }
            m_aData[m_nLength++] = mElement;
        }

        FORCEINLINE void Push(Array<T> lElements) {
            // TODO
        }

        FORCEINLINE void Push(T* aElements, RUINT nLength) {
            // TODO
        }

        FORCEINLINE T Peek() {
            return m_nLength > 0 ? m_aData[m_nLength-1] : (T)0;
        }

        FORCEINLINE Array<T> Peek(RUINT nLength) {
            nLength = min(m_nLength, nLength);
            Array<T> lReturn = Array<T>(nLength, m_nBlockSize);
            COPY(&m_aData[m_nLength - nLength], lReturn.m_aData, nLength * sizeof(T));
            lReturn.m_nLength = nLength;
            return lReturn;
        }

        FORCEINLINE T Pop() {
            return m_nLength > 0 ? m_aData[--m_nLength] : (T)0;
        }

        FORCEINLINE Array<T> Pop(RUINT nLength) {
            nLength = min(m_nLength, nLength);
            Array<T> lReturn = Array<T>(nLength, m_nBlockSize);
            COPY(&m_aData[m_nLength - nLength], lReturn.m_aData, nLength * sizeof(T));
            lReturn.m_nLength = nLength;
            m_nLength -= nLength;
            return lReturn;
        }

        FORCEINLINE void Clear() {
            m_nLength = 0;
        }

        FORCEINLINE void Insert(T mElement, RUINT nIndex) {
            // TODO
        }

        FORCEINLINE RINT FirstIndexOf(T mElement) const {
            for(int i=0 ; i<m_nLength ; ++i) {
                if(m_aData[i] == mElement) return i;
            }
            return -1;
        }

        FORCEINLINE RINT LastIndexOf(T mElement) const {
            for(int i=m_nLength-1 ; i>-1 ; --i) {
                if(m_aData[i] == mElement) return i;
            }
            return -1;
        }

        FORCEINLINE RBOOL RemoveElement(T mElement) {
            // TODO
            return false;
        }

        FORCEINLINE RBOOL RemoveIndex(RUINT nIndex) {
            // TODO
            return false;
        }

        FORCEINLINE RBOOL Increase(RUINT nIncrease) {
            return Resize(m_nCapacity + nIncrease);
        }

        FORCEINLINE RBOOL Decrease(RUINT nDecrease) {
            return Resize(m_nCapacity - nDecrease);
        }

        FORCEINLINE void Resize(RUINT nCapacity) {
            if(nCapacity < 0 || nCapacity > 100000) 
                return false;

            m_nCapacity = nCapacity;
            T* aTmp = new T[m_nLength];
            COPY(m_aData, aTmp, m_nLength * sizeof(T));
            SAFE_DELETE_ARRAY(m_aData);
            m_aData = aTmp;
            return true;
        }

        FORCEINLINE RUINT Length() const {
            return m_nLength;
        }

        FORCEINLINE RUINT Capacity() const {
            return m_nCapacity;
        }

        FORCEINLINE RUINT BlockSize() const {
            return m_nBlockSize;
        }

        FORCEINLINE Array<T>& operator=(Array<T> const& oArray) {
            if(this != &oArray) {
                SAFE_DELETE_ARRAY(m_aData);
                m_nLength = oArray.m_nLength;
                m_nCapacity = oArray.m_nCapacity;
                m_nBlockSize = oArray.m_nBlockSize;
                m_aData = new T[m_nCapacity];
                COPY(oArray.m_aData, m_aData, m_nCapacity * sizeof(T));
            }
            return *this;
        }

    private:
        T* m_aData;
        RUINT m_nLength;
        RUINT m_nCapacity;
        RUINT m_nBlockSize;
    };

    //#include "../inl/Array.inl"
};

#endif // _H_ROCK_ARRAY