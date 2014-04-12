#include "JadeStd.h"
#include "FileRef.h"
#include "IFile.h"

using namespace Rock;
using namespace Jade;

FileRef::FileRef() : m_pPtr(NULL) {
	m_pnCount = new UInt32();
	(*m_pnCount) = 1;
}

FileRef::FileRef(IFile *pRef) : m_pPtr(pRef) {
	m_pnCount = new UInt32();
	(*m_pnCount) = 1;
}

FileRef::~FileRef() {
	--(*m_pnCount);
	if((*m_pnCount) == 0) {
		delete m_pPtr;
		delete m_pnCount;
	}
}

FileRef::FileRef(FileRef const& ref) : m_pPtr(ref.m_pPtr), m_pnCount(ref.m_pnCount) {
	++(*m_pnCount);
}

FileRef& FileRef::operator=(FileRef const& ref) {
	if(&ref != this) {
		--(*m_pnCount);
		if((*m_pnCount) == 0) {
			delete m_pPtr;
			delete m_pnCount;
		}
		m_pPtr = ref.m_pPtr;
		m_pnCount = ref.m_pnCount;
		++(*m_pnCount);
	}
	return *this;
}

IFile*	FileRef::operator->() {
	return m_pPtr;
}