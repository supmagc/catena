#include "JadeStd.h"
#include "LinkedFile.h"
#include "LinkedFileSystem.h"

using namespace Rock;
using namespace Jade;
using namespace boost::filesystem;

LinkedFile::LinkedFile(LinkedFileSystem *pFileSystem, boost::filesystem::wpath const& filePath) : 
	m_pFileSystem(pFileSystem), 
	m_FilePath(filePath),
	m_sFileName(filePath.filename().c_str()),
	m_sFileExt(filePath.extension().c_str()) {
	m_sFileExt = m_sFileExt.SubString(1);
	_wfopen_s(&m_pFile, m_FilePath.string().c_str(), L"rb");
}

LinkedFile::~LinkedFile() {
}

IFileSystem* LinkedFile::GetFileSystem() {
	return m_pFileSystem;
}

UInt32 LinkedFile::GetFileSize() const {
	return Exists() ? static_cast<UInt32>(boost::filesystem::file_size(m_FilePath)) : 0;
}

Str const& LinkedFile::GetFileName() const {
	return m_sFileName;
}

Str const& LinkedFile::GetFileExt() const {
	return m_sFileExt;
}

Bool LinkedFile::Exists() const {
	return exists(m_FilePath);
}

UInt32 LinkedFile::Read(Byte const* aData, UInt32 nLength) {
	return nLength;
}
