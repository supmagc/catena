#ifndef _H_JADE_FILEREF
#define _H_JADE_FILEREF

#include "JadeStd.h"

namespace Jade {

	class IFile;
	class JADE_API FileRef {
	public:
		FileRef();
		FileRef(IFile *pRef);
		~FileRef();
		FileRef(FileRef const& ref);
		FileRef& operator=(FileRef const& ref);
		IFile*	operator->();

	private:
		Rock::UInt32 *m_pnCount;
		IFile *m_pPtr;
	};
};

#endif