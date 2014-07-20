
#include "Diamond_Std.h"
#include "Diamond_Mesh.h"

using namespace Diamond;

PIMPL_MAKE(Diamond, Mesh) {
    Core* pCore;
    IDevice* pDevice;

    IShader* pShader;
    IVertexBuffer* pVertices;
    RFLOAT nTemp, nDir;
};

Mesh::Mesh(Core* pCore, IDevice* pDevice) {
    PIMPL_INIT(Mesh);
    CHECK_NOTNULL(pCore);
    CHECK_NOTNULL(pDevice);

    PIMPL.pCore = pCore;
    PIMPL.pDevice = pDevice;

    // TEMP TESTING STUFF
    PIMPL.pShader = new Chalk::D3d9::Shader(dynamic_cast<Chalk::D3d9::Device*>(PIMPL.pDevice));
    PIMPL.pShader->Load();
    
    PIMPL.pVertices = new Chalk::D3d9::VertexBuffer(dynamic_cast<Chalk::D3d9::Device*>(PIMPL.pDevice));
    PIMPL.pVertices->Load();

    PIMPL.nDir = 1;
}

Mesh::~Mesh() {
    PIMPL_DELETE();
}

void Mesh::Draw() {
    PIMPL.pShader->Set();

    Matrix mWorld = Matrix();
    PIMPL.nTemp += PIMPL.nDir * 0.01f;
    if(PIMPL.nTemp > 5) {PIMPL.nTemp = 5; PIMPL.nDir =-1;}
    if(PIMPL.nTemp <-5) {PIMPL.nTemp =-5; PIMPL.nDir = 1;}
    Matrix mView = Matrix::CreateViewLH(Vector(PIMPL.nTemp, 0, -2), Vector(0, 0, 0), Vector3(0, 1, 0));
    Matrix mProj = Matrix::CreatePerspectiveLH(45, 1024.0f/768.0f, 0.1f, 100);
    Matrix mWVP = mView * mProj;
    PIMPL.pShader->SetData(mWVP.v, 4);

    PIMPL.pVertices->Set();
}
