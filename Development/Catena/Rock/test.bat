setlocal
cd D:\code\Catena\Development\Catena\Rock
if %errorlevel% neq 0 goto :cmEnd
D:
if %errorlevel% neq 0 goto :cmEnd
D:\code\Catena\Development\Catena\..\Dependencies\\swigwin-3.0.0\swig.exe -c++ -csharp -namespace Rock -outdir D:/code/Catena/Development/Catena/../CatenaEd/CatenaCSharp/Rock D:/code/Catena/Development/Catena/Rock/swig/rock_swig.i
if %errorlevel% neq 0 goto :cmEnd
:cmEnd
endlocal & call :cmErrorLevel %errorlevel% & goto :cmDone
:cmErrorLevel
exit /b %1
:cmDone
if %errorlevel% neq 0 goto :VCEnd