#include "JadeStd.h"
#include "LinkedFileSystem.h"
#include "LinkedFile.h"

using namespace Jade;
using namespace Rock;
using namespace boost::filesystem;

LinkedFileSystem::LinkedFileSystem(Rock::Str const& sRootPath) : m_RootPath(sRootPath.GetData()) {

	if(!exists(m_RootPath)) {
		create_directories(m_RootPath);
	}
	if(!is_directory(m_RootPath)) {
		throw NoDirectoryException("You are creating a linked filesystem with a none-directory rootpath.");
	}
}

LinkedFileSystem::~LinkedFileSystem() {
}

FileRef LinkedFileSystem::GetFile(Str const& sFilePath) {
	return FileRef(new LinkedFile(this, m_RootPath / boost::filesystem::wpath(sFilePath.GetData())));
}

Bool LinkedFileSystem::Exists(Str const& sFilePath) const {
	return false;
}

Bool LinkedFileSystem::CreateFile(Str const& sFilePath, Byte const* aData, UInt32 nLength) {
	return false;
}

void LinkedFileSystem::Release() {
	delete this;
}