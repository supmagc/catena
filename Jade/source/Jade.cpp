#include "JadeStd.h"
#include "Jade.h"

#include "LinkedFileSystem.h"

using namespace Rock;
using namespace Jade;

JADE_API IFileSystem* Jade::CreateLinkedFileSystem(Str const& sRootPath) {
	return new LinkedFileSystem(sRootPath);
}

JADE_API void Jade::Destroy(IFileSystem * pFS) {
	if(pFS) pFS->Release();
}