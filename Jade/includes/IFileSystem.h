#ifndef _H_JADE_IFILESYSTEM
#define _H_JADE_IFILESYSTEM

#include "JadeStd.h"
#include "FileRef.h"

namespace Jade {

	class IFile;
	class JADE_API IFileSystem {
	public:
		virtual FileRef GetFile(Rock::Str const& sFilePath) =0;
		virtual Rock::Bool Exists(Rock::Str const& sFilePath) const =0;
		virtual Rock::Bool CreateFile(Rock::Str const& sFilePath, Rock::Byte const* aData, Rock::UInt32 nLength) =0;
		virtual void Release() =0;

	protected:
		IFileSystem() {}
		virtual ~IFileSystem() {}

	private:
		IFileSystem(IFileSystem const&);
		IFileSystem& operator=(IFileSystem const&);
	};

};

#endif