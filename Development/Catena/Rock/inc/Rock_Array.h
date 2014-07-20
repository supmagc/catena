#ifndef _H_ROCK_ARRAY
#define _H_ROCK_ARRAY 1

#include "Rock_Defines.h"
#include "Rock_Types.h"
#include "Rock_Checks.h"
#include "Rock_Allocators.h"

namespace Rock {

    template<typename ElementType, typename AllocatorType = HeapAllocator::ByType<ElementType>, typename SizeType = RUINT, SizeType SizeMax = RUINT_MAX, SizeType ElementSize = sizeof(ElementType) >
    class Array {
    public:

        typedef Array<ElementType, AllocatorType, SizeType, SizeMax, ElementSize> Type;

        Array(SizeType nCapacity = DEFAULT_ARRAY_CAPACITY, SizeType nBlockSize = DEFAULT_ARRAY_BLOCKSIZE) : m_nLength(0), m_nCapacity(nCapacity), m_nBlockSize(nBlockSize), m_oData() {
            m_oData.Resize(0, m_nCapacity, ElementSize);
        }

        Array(Type const& lOther) : m_nLength(lOther.m_nLength), m_nCapacity(lOther.m_nLength), m_nBlockSize(lOther.m_nBlockSize) {
            m_oData.Resize(0, lOther.m_nLength, sizeof(ElementType));
            catMemCopy(lOther.m_oData.GetData(), m_oData.GetData(), m_nLength * ElementSize);
        }

        Array(std::initializer_list<ElementType> const& oInitialer, SizeType nBlockSize = DEFAULT_ARRAY_BLOCKSIZE) : m_nLength(oInitialer.size()), m_nCapacity(oInitialer.size()), m_nBlockSize(nBlockSize) {
            m_oData.Resize(0, m_nCapacity, ElementSize);
            for(auto i = oInitialer.begin(); i != oInitialer.end(); ++i) {
                m_oData.GetData()[m_nLength++] = *i;
            }
        }

        Array(ElementType* aOther, SizeType nLength, SizeType nBlockSize = DEFAULT_ARRAY_BLOCKSIZE) : m_nLength(nLength), m_nCapacity(nLength), m_nBlockSize(nBlockSize) {
            m_oData.Resize(0, m_nCapacity, ElementSize);
            catMemCopy(aOther, m_oData.GetData(), m_nLength * ElementSize);
        }

        ~Array() {
        }

        FORCEINLINE void Push(ElementType mElement) {
            if(m_nLength >= m_nCapacity) Increase(m_nBlockSize);
            m_oData.GetData()[m_nLength++] = mElement;
        }

        FORCEINLINE void Push(Type const& lOther) {
            SizeType nLengthTotal = m_nLength + lOther.m_nLength;
            if(nLengthTotal >= m_nCapacity) Resize(nLengthTotal + m_nBlockSize);
            catMemCopy(lOther.m_oData.GetData(), &m_oData.GetData()[m_nLength], lOther.m_nLength * ElementSize);
            m_nLength = nLengthTotal;
        }

        FORCEINLINE ElementType Peek() const {
            CHECK_SLOW(m_nLength > 0);
            return m_oData.GetData()[m_nLength - 1];
        }

        FORCEINLINE Type Peek(SizeType nLength) const {
            CHECK_SLOW(m_nLength <= m_nLength);
            Type lReturn(nLength, m_nBlockSize);
            catMemCopy(&m_oData.GetData()[m_nLength - nLength], lReturn.m_oData.GetData(), nLength * ElementSize);
            return lReturn;
        }

        FORCEINLINE ElementType Pop() {
            CHECK_SLOW(m_nLength > 0);
            return m_oData.GetData()[--m_nLength];
        }

        FORCEINLINE Type Pop(SizeType nLength) {
            CHECK_SLOW(m_nLength <= m_nLength);
            Type lReturn(nLength, m_nBlockSize);
            catMemCopy(&m_oData.GetData()[m_nLength - nLength], lReturn.m_oData.GetData(), nLength * ElementSize);
            m_nLength -= nLength;
            return lReturn;
        }

        FORCEINLINE void Clear() {
            m_nLength = 0;
        }

        FORCEINLINE RBOOL Contains(ElementType const& mElement) const {
            SizeType nIndex;
            return FirstIndexOf(mElement, nIndex);
        }

        FORCEINLINE RBOOL FirstIndexOf(ElementType const& mElement, SizeType& o_nIndex) const {
            for(o_nIndex=0 ; o_nIndex<m_nLength ; ++o_nIndex) {
                if(m_oData.GetData()[o_nIndex] == mElement) return true;
            }
            return false;
        }

        FORCEINLINE RINT LastIndexOf(ElementType const& mElement, SizeType& o_nIndex) const {
            for(o_nIndex=m_nLength-1 ; o_nIndex>-1 ; --o_nIndex) {
                if(m_oData.GetData()[o_nIndex] == mElement) return true;
            }
            return false;
        }

        //FORCEINLINE void Insert(T mElement, S nIndex) {
        //    CHECK_SLOW(nIndex >= 0 && nIndex < m_nLength);


        //}

        FORCEINLINE SizeType RemoveElement(ElementType mElement) {
            SizeType nRemoved = 0;
            SizeType nIndex = INDEX_NONE;
            while(FirstIndexOf(mElement, nIndex)) {
                RemoveIndex(nIndex);
                ++nRemoved;
            }
            return nRemoved;
        }

        FORCEINLINE void RemoveIndex(SizeType nIndex) {
            CHECK_SLOW(nIndex >= 0 && nIndex < m_nLength);
            RUINT nBefore = nIndex * ElementSize;
            RUINT nAfter = (m_nLength - nIndex - 1) * ElementSize;
            catMemMove(m_oData.GetData() + nBefore + ElementSize, m_oData.GetData() + nBefore, nAfter);
        }

        FORCEINLINE void Increase(SizeType nIncrease = 0) {
            if(nIncrease <= 0) Resize(m_nLength / 2 + 1);
            else Resize(m_nCapacity + nIncrease);
        }

        FORCEINLINE void Decrease(SizeType nDecrease = 0) {
            if (nDecrease > m_nLength) Resize(0);
            else if (nDecrease <= 0) Resize(m_nLength);
            else Resize(m_nCapacity - nDecrease);
        }

        FORCEINLINE void Resize(SizeType nCapacity) {
            CHECK_SLOW(nCapacity > 0 && nCapacity <= SizeMax);
            m_oData.Resize(m_nCapacity, nCapacity, ElementSize);
            m_nCapacity = nCapacity;
        }

        FORCEINLINE SizeType Length() const {
            return m_nLength;
        }

        FORCEINLINE SizeType Capacity() const {
            return m_nCapacity;
        }

        FORCEINLINE SizeType BlockSize() const {
            return m_nBlockSize;
        }

        FORCEINLINE Type& operator=(Type lOther) {
            catSwap(*this, lOther);
            return *this;
        }

        FORCEINLINE ElementType const& operator[](SizeType nIndex) const {
            CHECK_SLOW(nIndex >= 0 && nIndex < m_nLength);
            return m_oData.GetData()[nIndex];
        }

        FORCEINLINE ElementType& operator[](SizeType nIndex) {
            CHECK_SLOW(nIndex >= 0 && nIndex < m_nLength);
            return m_oData.GetData()[nIndex];
        }

    private:
        AllocatorType m_oData;
        SizeType m_nLength;
        SizeType m_nCapacity;
        SizeType m_nBlockSize;
    };
};

#endif // _H_ROCK_ARRAY