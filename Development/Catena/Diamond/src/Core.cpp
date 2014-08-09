#include "Diamond_Std.h"
#include "Diamond_Core.h"
#include "Diamond_Scene.h"
#include "Diamond_WindowCanvas.h"
#include "Diamond_InteractiveViewer.h"

using namespace Diamond;

PIMPL_MAKE(Diamond, Core) {
    IDevice* pDevice;
    Array<Scene*> lScenes;
};

Core::Core() {
    PIMPL_INIT(Core);
    PIMPL.pDevice = new Chalk::D3d9::Device();
}

Core::~Core() {
    CHECK_SLOW_TRUE(PIMPL.lScenes.Length() == 0);
    SAFE_DELETE(PIMPL.pDevice);
    catOutputLog("-- SCENE CLEANUP");
    PIMPL_DELETE();
}

Scene* Core::CreateScene() {
    Scene* pScene = new Scene(this, PIMPL.pDevice);
    PIMPL.lScenes.Push(pScene);
    return pScene;
}

WindowCanvas* Core::CreateWindowCanvas() {
    return new WindowCanvas(this, PIMPL.pDevice);
}

InteractiveViewer* Core::CreateInteractiveViewer() {
    return new InteractiveViewer(this, PIMPL.pDevice);
}

Array<Scene*> const& Core::GetScenes() const {
    return PIMPL.lScenes;
}

RBOOL Core::Update() {
    for(RUINT i = 0 ; i < PIMPL.lScenes.Length() ; ++i) {
        PIMPL.lScenes[i]->Update(0.05f);
    }
    return true;
}

void Core::Release(Scene* pScene) {
    CHECK_NOTNULL(pScene);
    CHECK_TRUE(pScene->GetCore() == this);
    PIMPL.lScenes.RemoveElement(pScene);
    delete pScene;
}

void Core::Release(WindowCanvas* pCanvas) {
    CHECK_NOTNULL(pCanvas);
    CHECK_TRUE(pCanvas->GetCore() == this);
    delete pCanvas;
}

void Core::Release(InteractiveViewer* pViewer) {
    CHECK_NOTNULL(pViewer);
    CHECK_TRUE(pViewer->GetCore() == this);
    delete pViewer;
}
