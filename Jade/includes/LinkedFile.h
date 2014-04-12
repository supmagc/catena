#ifndef _H_JADE_LINKEDFILE
#define _H_JADE_LINKEDFILE

#include "IFile.h"
#include <boost\filesystem.hpp>
#include <iostream>

namespace Jade {

	class LinkedFileSystem;
	class LinkedFile : public IFile {
	public:
		LinkedFile(LinkedFileSystem * pFileSystem, boost::filesystem::wpath const& filePath);
		virtual ~LinkedFile();
		virtual IFileSystem* GetFileSystem();
		virtual Rock::UInt32 GetFileSize() const;
		virtual Rock::Str const& GetFileName() const;
		virtual Rock::Str const& GetFileExt() const;
		virtual Rock::Bool Exists() const;
		virtual Rock::UInt32 Read(Rock::Byte const* aData, Rock::UInt32 nLength);

	private:
		Rock::Str m_sFileName;
		Rock::Str m_sFileExt;
		boost::filesystem::wpath m_FilePath;
		LinkedFileSystem * m_pFileSystem;
		FILE * m_pFile;
	};
};

#endif