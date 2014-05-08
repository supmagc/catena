
set(CATENA_VERSION_MAJOR 1
	CACHE STRING "Major version number of this build.")
set(CATENA_VERSION_MINOR 0
	CACHE STRING "Minor version number of this build.")
set(CATENA_DEPENDENCIES "../Dependencies/"
	CACHE PATH "Path to the dependencies (required to build Catena).")
set(CATENA_LAUNCHER_NAME "Launcher"
	CACHE STRING "Name of the final launcher.")
set(CATENA_LAUNCHER_ALLINONE 1
	CACHE BOOL "Try to make an all ine one executable (use static libraries).")
set(CATENA_LAUNCHER_SUPPORT_D3D9 1
	CACHE BOOL "Enable support for d3d9.")
set(CATENA_LAUNCHER_SUPPORT_D3D11 1
	CACHE BOOL "Enable support for d3d11.")
set(CATENA_LAUNCHER_SUPPORT_OPENGL 1
	CACHE BOOL "Enable support for opengl.")

if(WIN32 AND CATENA_LAUNCHER_SUPPORT_D3D9)
	set(WITH_D3D9 1)
endif()

if(WIN32 AND CATENA_LAUNCHER_SUPPORT_D3D11)
	set(WITH_D3D11 1)
endif()

if(CATENA_LAUNCHER_SUPPORT_OPENGL)
	set(WITH_OPENGL 1)
endif()
