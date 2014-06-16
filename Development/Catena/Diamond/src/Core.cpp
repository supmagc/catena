#include "Diamond_Std.h"
#include "Diamond_Core.h"
#include "Diamond_Scene.h"
#include "Diamond_SceneView.h"

using namespace Diamond;

PIMPL_MAKE(Diamond, Core) {
    IDevice* pDevice;
    IShader* pShader;
    IVertexBuffer *pVertexBuffer;
    vector<SceneView*> lSceneViews;
};

Core::Core() {
    PIMPL_INIT(Core);
}

Core::~Core() {
    SAFE_DELETE(PIMPL.pVertexBuffer);
    SAFE_DELETE(PIMPL.pShader);
    SAFE_DELETE(PIMPL.pDevice);
    PIMPL_DELETE();
}

Scene* Core::GetScene() {
    return RNULL;
}

SceneView* Core::Create(RINT hWnd, RUINT nWidth, RUINT nHeight, RBOOL bFullscreen) {
    Chalk::D3d9::Device::CreateSwapChainSettings oSettings;
    oSettings.hWindow = (HWND)hWnd;

    Chalk::RenderSettings oRenderSettings;
    oRenderSettings.nWidth = nWidth;
    oRenderSettings.nHeight = nHeight;
    oRenderSettings.bFullscreen = bFullscreen;

    PIMPL.pDevice = new Chalk::D3d9::Device();
    ISwapChain* pSwapChain = PIMPL.pDevice->CreateSwapChain(&oSettings, &oRenderSettings);
    ASSERT_NOTNULL(pSwapChain);

    SceneView* pSceneView = new SceneView(pSwapChain);

    // TEMP TESTING STUFF
    m_pImpl->pShader = new Chalk::D3d9::Shader(dynamic_cast<Chalk::D3d9::Device*>(m_pImpl->pDevice));
    if(!m_pImpl->pShader->Load())
        return false;

    m_pImpl->pVertexBuffer = new Chalk::D3d9::VertexBuffer(dynamic_cast<Chalk::D3d9::Device*>(m_pImpl->pDevice));
    if(!m_pImpl->pVertexBuffer->Load())
        return false;

    PIMPL.lSceneViews.push_back(pSceneView);

    return pSceneView;
}

RFLOAT g_nDir = 1;
RFLOAT g_nTemp = 0;

RBOOL Core::Update() {
    RBOOL bError = false;

    ASSERT(m_pImpl->pDevice != RNULL);
    ASSERT(m_pImpl->pShader != RNULL);

    for(auto i=PIMPL.lSceneViews.begin() ; i!=PIMPL.lSceneViews.end() ; ++i) {
        (*i)->GetSwapChain()->Activate();
        bError = bError || !m_pImpl->pDevice->Clear();
        bError = bError || !m_pImpl->pShader->Set();

        Matrix mWorld = Matrix();
        g_nTemp += g_nDir * 0.01f;
        if(g_nTemp > 5) {g_nTemp = 5; g_nDir =-1;}
        if(g_nTemp <-5) {g_nTemp =-5; g_nDir = 1;}
        Matrix mView = Matrix::CreateViewLH(Vector(g_nTemp, 0, -2), Vector(0, 0, 0), Vector3(0, 1, 0));
        Matrix mProj = Matrix::CreatePerspectiveLH(45, 1024.0f/768.0f, 0.1f, 100);
        Matrix mWVP = mView * mProj;
        PIMPL.pShader->SetData(mWVP.v, 4);

        bError = bError || !m_pImpl->pVertexBuffer->Set();
        bError = bError || !m_pImpl->pDevice->Switch();
    }

    return !bError;
}