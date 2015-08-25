#ifndef _H_ROCK_ALLOCATORS
#define _H_ROCK_ALLOCATORS 1

#include "Rock_Defines.h"
#include "Rock_Functions.h"
#include "Rock_Types.h"
#include "Rock_Checks.h"
#include "Rock_Log.h"

namespace Rock {

    class HeapAllocator {
    public:

        class Boxed {
        public:
            Boxed() : m_pData(RNULL) {}
            ~Boxed() {
				LOGCAT_DEBUG(RTXT("Allocator"), RTXT("Memory freed up !!"));
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
        class ByType : public Boxed {
        public:
            ByType() : Boxed() {}

            ~ByType() {
				LOGCAT_DEBUG(RTXT("Allocator"), RTXT("Memory freed up !!"));
            }

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