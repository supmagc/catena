
#include "Diamond_Std.h"
#include "Diamond_Renderer.h"
#include "Diamond_ICanvas.h"
#include "Diamond_IViewer.h"
#include "Diamond_Scene.h"

// test mesh include
#include "Diamond_Mesh.h"

using namespace Diamond;

PIMPL_MAKE(Diamond, Renderer) {
    Scene* pScene;
    IDevice* pDevice;
    ICanvas* pCanvas;
    IViewer* pViewer;

    // test mesh
    Mesh* pMesh;
};

Renderer::Renderer(Scene* pScene, IDevice* pDevice) {
    PIMPL_INIT(Renderer);
    CHECK_NOTNULL(pScene);
    CHECK_NOTNULL(pDevice);
    PIMPL.pScene = pScene;
    PIMPL.pDevice = pDevice;

    // Test mesh creation
    PIMPL.pMesh = new Mesh(pScene->GetCore(), pDevice);
}

Renderer::~Renderer() {
    CHECK_SLOW_FALSE(PIMPL.pScene->GetRenderers().Contains(this));
    PIMPL_DELETE();
}

void Renderer::Draw() {
    // Draw stuff

    // Activate canvas
    PIMPL.pCanvas->Activate();
    PIMPL.pDevice->Clear();

    // Test draw
    PIMPL.pMesh->Draw();

    PIMPL.pDevice->Switch();
}

void Renderer::SetCanvas(ICanvas* pCanvas) {
    PIMPL.pCanvas = pCanvas;
}

void Renderer::SetViewer(IViewer* pViewer) {
    PIMPL.pViewer = pViewer;
}

ICanvas* Renderer::GetCanvas() {
    return PIMPL.pCanvas;
}

ICanvas const* Renderer::GetCanvas() const {
    return PIMPL.pCanvas;
}

IViewer* Renderer::GetViewer() {
    return PIMPL.pViewer;
}

IViewer const* Renderer::GetViewer() const {
    return PIMPL.pViewer;
}

Scene* Renderer::GetScene() {
    return PIMPL.pScene;
}

Scene const* Renderer::GetScene() const {
    return PIMPL.pScene;
}
