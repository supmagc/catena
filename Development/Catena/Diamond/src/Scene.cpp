
#include "Diamond_Std.h"
#include "Diamond_Scene.h"
#include "Diamond_Core.h"
#include "Diamond_Renderer.h"

using namespace Diamond;

PIMPL_MAKE(Diamond, Scene) {
    Core* pCore;
    IDevice* pDevice;
    Array<Renderer*> lRenderers;
};

Scene::Scene(Core* pCore, IDevice* pDevice) {
    PIMPL_INIT(Scene);
    CHECK_NOTNULL(pCore);
    CHECK_NOTNULL(pDevice);

    PIMPL.pCore = pCore;
    PIMPL.pDevice = pDevice;
}

Scene::~Scene() {
    catOutputLog("-- SCENE CLEANUP");

    CHECK_SLOW_FALSE(PIMPL.pCore->GetScenes().Contains(this));
    PIMPL_DELETE();
}

Core* Scene::GetCore() {
    return PIMPL.pCore;
}

Core const* Scene::GetCore() const {
    return PIMPL.pCore;
}

Renderer* Scene::CreateRenderer() {
    Renderer* pRenderer = new Renderer(this, PIMPL.pDevice);
    PIMPL.lRenderers.Push(pRenderer);
    return pRenderer;
}

Array<Renderer*> const& Scene::GetRenderers() const {
    return PIMPL.lRenderers;
}

void Scene::Update(float nDeltaTime, RBOOL bDrawAll) {
    if(bDrawAll) {
        for(RUINT i = 0 ; i < PIMPL.lRenderers.Length() ; ++i) {
            if(PIMPL.lRenderers[i]->CanDraw())
                PIMPL.lRenderers[i]->Draw();
        }
    }
}

void Scene::Release(Renderer* pRenderer) {
    CHECK_NOTNULL(pRenderer);
    CHECK_TRUE(pRenderer->GetScene() == this);
    PIMPL.lRenderers.RemoveElement(pRenderer);
    delete pRenderer;
}
