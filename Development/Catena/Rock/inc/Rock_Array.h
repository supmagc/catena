#ifndef _H_ROCK_ARRAY
#define _H_ROCK_ARRAY 1

#include "Rock_Defines.h"
#include "Rock_Types.h"
#include "Rock_Assert.h"

namespace Rock {

    template<typename T, typename S = RUINT, S S_MAX = RUINT_MAX>
    class ROCK_API Array {
    public:

        static const T DefaultValue = (T)0;
        typedef Array<T, S, S_MAX> Type;

        Array(S nCapacity = 2, S nBlockSize = 0) : m_nLength(0), m_nCapacity(nCapacity), m_nBlockSize(nBlockSize) {
            m_aData = new T[m_nCapacity];
        }

        Array(Type const& lOther) : m_nLength(lOther.m_nLength), m_nCapacity(lOther.m_nCapacity), m_nBlockSize(lOther.m_nBlockSize) {
            m_aData = new T[m_nCapacity];
            COPY(lOther.m_aData, m_aData, m_nLength * sizeof(T));
        }

		Array(std::initializer_list<T> const& oInitialer, S nBlockSize = 0) : m_nLength(0), m_nCapacity(oInitialer.size()), m_nBlockSize(nBlockSize) {
			m_aData = new T[m_nCapacity];
			for(auto i = oInitialer.begin(); i != oInitialer.end(); ++i) {
				m_aData[m_nLength++] = *i;
			}
		}

        Array(T* aOther, S nLength, S nBlockSize = 0) : m_nLength(nLength), m_nCapacity(nLength), m_nBlockSize(nBlockSize) {
            m_aData = new T[m_nCapacity];
            COPY(aOther, m_aData, m_nLength * sizeof(T));
        }

        ~Array() {
            SAFE_DELETE_ARRAY(m_aData);
        }

        FORCEINLINE RBOOL Push(T mElement) {
            if(m_nLength < m_nCapacity || Increase(m_nBlockSize)) {
                m_aData[m_nLength++] = mElement;
                return true;
            }
            return false;
        }

        FORCEINLINE RBOOL Push(Array<T> const& lElements) {
            S nLengthTotal = m_nLength + lElements.Length;
            if(nLengthTotal <= m_nCapacity || Resize(nLengthTotal)) {
                COPY(lElements.m_aData, &m_aData[m_nLength], lElements.m_nLength * sizeof(T));
                m_nLength = nLengthTotal;
                return true;
            }
            return false;
        }

        FORCEINLINE T Peek() {
            return m_nLength > 0 ? m_aData[m_nLength-1] : (T)0;
        }

        FORCEINLINE Array<T> Peek(S nLength) {
            nLength = min(m_nLength, nLength);
            Array<T> lReturn = Array<T>(nLength, m_nBlockSize);
            COPY(&m_aData[m_nLength - nLength], lReturn.m_aData, nLength * sizeof(T));
            lReturn.m_nLength = nLength;
            return lReturn;
        }

        FORCEINLINE T Pop() {
            return m_nLength > 0 ? m_aData[--m_nLength] : (T)0;
        }

        FORCEINLINE Array<T> Pop(S nLength) {
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

        FORCEINLINE void Insert(T mElement, S nIndex) {
            // TODO
        }

        FORCEINLINE RBOOL FirstIndexOf(T mElement, S& o_nIndex) const {
            for(o_nIndex=0 ; o_nIndex<m_nLength ; ++o_nIndex) {
                if(m_aData[o_nIndex] == mElement) return true;
            }
            return false;
        }

        FORCEINLINE RINT LastIndexOf(T mElement, S& o_nIndex) const {
            for(o_nIndex=m_nLength-1 ; o_nIndex>-1 ; --o_nIndex) {
                if(m_aData[o_nIndex] == mElement) return true;
            }
            return false;
        }

        FORCEINLINE RBOOL RemoveElement(T mElement) {
            // TODO
            return false;
        }

        FORCEINLINE RBOOL RemoveIndex(S nIndex) {
            // TODO
            return false;
        }

        FORCEINLINE RBOOL Increase(S nIncrease = m_nBlockSize) {
            if(nIncrease <= 0) nIncrease = m_nLength / 2 + 1;
            return Resize(m_nCapacity + nIncrease);
        }

        FORCEINLINE RBOOL Decrease(S nDecrease = m_nBlockSize) {
            nDecrease = max(1, nDecrease);
            return Resize(m_nCapacity - nDecrease);
        }

        FORCEINLINE RBOOL Resize(S nCapacity) {
            if(nCapacity < 0 || nCapacity > S_MAX) 
                return false;

            m_nCapacity = nCapacity;
            m_nLength = min(m_nCapacity, m_nLength);
            T* aTmp = new T[m_nLength];
            COPY(m_aData, aTmp, m_nLength * sizeof(T));
            SAFE_DELETE_ARRAY(m_aData);
            m_aData = aTmp;
            return true;
        }

        FORCEINLINE S Length() const {
            return m_nLength;
        }

        FORCEINLINE S Capacity() const {
            return m_nCapacity;
        }

        FORCEINLINE S BlockSize() const {
            return m_nBlockSize;
        }

        FORCEINLINE void Swap(Type lArray) {
            std::swap(m_aData, lArray.m_aData);
            std::swap(m_nLength, lArray.m_nLength);
            std::swap(m_nCapacity, lArray.m_nCapacity);
            std::swap(m_nBlockSize, lArray.m_nBlockSize);
        }

        FORCEINLINE Array<T>& operator=(Type lOther) {
            // Copy and swap idiom
            // argument by value, is thus a copy form the original
            // swap resources with this (and old values are in temp)
            // gets cleaned up on function exit, 
            lOther.Swap(*this);
            return *this;
        }

        FORCEINLINE T const& operator[](S nIndex) const {
            if(nIndex >= 0 && nIndex < m_nLength)
                return m_aData[nIndex];
            return DefaultValue;
        }

    private:
        T* m_aData;
        S m_nLength;
        S m_nCapacity;
        S m_nBlockSize;
    };

    //#include "../inl/Array.inl"
};

#endif // _H_ROCK_ARRAY