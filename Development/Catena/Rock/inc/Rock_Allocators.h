#ifndef _H_ROCK_ALLOCATORS
#define _H_ROCK_ALLOCATORS 1

#include "Rock_Defines.h"
#include "Rock_Functions.h"
#include "Rock_Types.h"
#include "Rock_Checks.h"

namespace Rock {

    class ROCK_API HeapAllocator {
    public:

        class ROCK_API Boxed {
        public:
            Boxed() : m_pData(RNULL) {}
            ~Boxed() {
                catMemFree(m_pData);
                m_pData = RNULL;
            }

            INLINE void Resize(RUINT nOldCount, RUINT nNewCount, RUINT nElementSize) {
                m_pData = catMemRealloc(m_pData, nNewCount*nElementSize, DEFAULT_ALIGNMENT);
            }

            INLINE RBOX GetData() const {
                return m_pData;
            }

        private:
            RBOX m_pData;
        };

        template<typename ElementType>
        class ROCK_API ByType : public Boxed {
        public:
            ByType() : Boxed() {}

            INLINE ElementType* GetData() const {
                return (ElementType*)Boxed::GetData();
            }
        };

    };

    class AlignedHeapAllocator {

    };

    class MemStackAllocator {

    };

    class AlignedMemStackAllocator {

    };
};

#endif // _H_ROCK_ALLOCATORS