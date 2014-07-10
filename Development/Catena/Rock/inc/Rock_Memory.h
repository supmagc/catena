#ifndef _H_ROCK_MEMORY
#define _H_ROCK_MEMORY 1

#include "Rock_Defines.h"
#include "Rock_Types.h"

namespace Rock {

    struct MemStack {

        MemStack* pNext;
        RPTR pEnd;
        RPTR pTop;
    };

    class StackAllocator {
    public:

    private:
        MemStack* m_pUsedStacks;
        MemStack* m_pUnusedStacks;
    };
};

#endif // _H_ROCK_MEMORY