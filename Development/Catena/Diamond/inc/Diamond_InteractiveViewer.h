#ifndef _H_DIAMOND_INTERACTIVEVIEWER
#define _H_DIAMOND_INTERACTIVEVIEWER 1

#include "Diamond_Defines.h"
#include "Diamond_IViewer.h"

#include "Chalk.h"

namespace Diamond {

    class Core;

    class DIAMOND_API InteractiveViewer : public IViewer {
    public:
        InteractiveViewer(Core* pCore, IDevice* pDevice);
        virtual ~InteractiveViewer();

        Core* GetCore();
        Core const* GetCore() const;

    private:
        PIMPL_DECL(InteractiveViewer);
        CLASS_NOCOPY(InteractiveViewer);
    };
};

#endif // _H_DIAMOND_INTERACTIVEVIEWER