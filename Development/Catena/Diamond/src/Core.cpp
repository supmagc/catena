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
    SAFE_DELETE(PIMPL.pDevice);
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
    //RBOOL bError = false;

    //CHECK(m_pImpl->pDevice != RNULL);
    //CHECK(m_pImpl->pShader != RNULL);

    //for(int i = 0 ; i < PIMPL.lSceneViews.Length() ; ++i) { 
    //    PIMPL.lSceneViews[i]->GetSwapChain()->Activate();
    //    bError = bError || !m_pImpl->pDevice->Clear();
    //    bError = bError || !m_pImpl->pShader->Set();

    //    Matrix mWorld = Matrix();
    //    g_nTemp += g_nDir * 0.01f;
    //    if(g_nTemp > 5) {g_nTemp = 5; g_nDir =-1;}
    //    if(g_nTemp <-5) {g_nTemp =-5; g_nDir = 1;}
    //    Matrix mView = Matrix::CreateViewLH(Vector(g_nTemp, 0, -2), Vector(0, 0, 0), Vector3(0, 1, 0));
    //    Matrix mProj = Matrix::CreatePerspectiveLH(45, 1024.0f/768.0f, 0.1f, 100);
    //    Matrix mWVP = mView * mProj;
    //    PIMPL.pShader->SetData(mWVP.v, 4);

    //    bError = bError || !m_pImpl->pVertexBuffer->Set();
    //    bError = bError || !m_pImpl->pDevice->Switch();
    //}

    //return !bError;
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
