#ifndef _H_JADE_IFILE
#define _H_JADE_IFILE

#include "JadeStd.h"

namespace Jade {

	class IFileSystem;
	class JADE_API IFile {
	public:
		virtual ~IFile() {}
		virtual IFileSystem* GetFileSystem() =0;
		virtual Rock::UInt32 GetFileSize() const =0;
		virtual Rock::Str const& GetFileName() const =0;
		virtual Rock::Str const& GetFileExt() const =0;
		virtual Rock::Bool Exists() const =0;
		virtual Rock::UInt32 Read(Rock::Byte const* aData, Rock::UInt32 nLength) =0;

	protected:
		IFile() {}
	};
};

#endif