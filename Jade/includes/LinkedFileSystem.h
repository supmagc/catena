#ifndef _H_JADE_LINKEDFILESYSTEM
#define _H_JADE_LINKEDFILESYSTEM

#include "IFileSystem.h"
#include <boost\filesystem.hpp>

namespace Jade {

	class LinkedFileSystem : public IFileSystem {
	public:
		LinkedFileSystem(Rock::Str const& sRootPath);
		virtual ~LinkedFileSystem();

		virtual FileRef GetFile(Rock::Str const& sFilePath);
		virtual Rock::Bool Exists(Rock::Str const& sFilePath) const;
		virtual Rock::Bool CreateFile(Rock::Str const& sFilePath, Rock::Byte const* aData, Rock::UInt32 nLength);
		virtual void Release();

	private:
		boost::filesystem::wpath m_RootPath;

	private:
		LinkedFileSystem(LinkedFileSystem const&);
		LinkedFileSystem& operator=(LinkedFileSystem const&);
	};

};

#endif