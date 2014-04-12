// JadeTester.cpp : Defines the entry point for the console application.

#include "Jade.h"
#include <iostream>
#include <sstream>
#include <tchar.h>

using namespace std;
using namespace Rock;
using namespace Jade;

int _tmain(int argc, _TCHAR* argv[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetBreakAlloc(211);

	wcout << Str("Starting to test Jade!\n");

	IFileSystem * pFS = Jade::CreateLinkedFileSystem(Str("D:\\"));

	FileRef f0 = pFS->GetFile(Str("test.txt.txt"));
	FileRef f1 = f0;
	pFS = f0->GetFileSystem();
	wcout << "Exists: " << f0->Exists() << endl;
	wcout << "FileSize: " << f1->GetFileSize() << endl;
	wcout << "FileName: " << f0->GetFileName() << endl;
	wcout << "FileExt: " << f1->GetFileExt() << endl;

	Jade::Destroy(pFS);

	wchar_t tmp;
	wcin.get(tmp);
	return 0;
}