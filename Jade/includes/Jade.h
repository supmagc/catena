#ifndef _H_JADE
#define _H_JADE

#include "JadeStd.h"
#include "IFile.h"
#include "IFileSystem.h"

namespace Jade {

	JADE_API IFileSystem* CreateLinkedFileSystem(Rock::Str const& sRootPath);
	JADE_API void Destroy(IFileSystem * pFS);
}

#endif