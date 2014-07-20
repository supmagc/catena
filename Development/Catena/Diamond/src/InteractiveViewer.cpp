
#include "Diamond_Std.h"
#include "Diamond_InteractiveViewer.h"

using namespace Diamond;

PIMPL_MAKE(Diamond, InteractiveViewer) {
    Core* pCore;
    IDevice* pDevice;
};

InteractiveViewer::InteractiveViewer(Core* pCore, IDevice* pDevice) {
    PIMPL_INIT(InteractiveViewer);
    CHECK_NOTNULL(pCore);
    CHECK_NOTNULL(pDevice);
    PIMPL.pCore = pCore;
    PIMPL.pDevice = pDevice;
}

InteractiveViewer::~InteractiveViewer() {
    PIMPL_DELETE();
}

Core* InteractiveViewer::GetCore() {
    return PIMPL.pCore;
}

Core const* InteractiveViewer::GetCore() const {
    return PIMPL.pCore;
}