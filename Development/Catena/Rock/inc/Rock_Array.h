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
            m_aData = new T[nCapacity];
        }
        Array(Array<T> const& oArray);
        ~Array() {
            SAFE_DELETE_ARRAY(m_aData);
        }

        void Push(Element mElement) {
            m_aData[m_nLength++] = mElement;
        }
        Element Pop() {
            return m_aData[--m_nLength];
        }

        Array<T>& operator=(Array<T> const& oArray);

    private:
        T* m_aData;
        RUINT m_nLength;
        RUINT m_nCapacity;
        RUINT m_nBlockSize
    };

    //#include "../inl/Array.inl"
};

#endif // _H_ROCK_ARRAY