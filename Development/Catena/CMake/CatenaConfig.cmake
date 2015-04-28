
set(CATENA_VERSION_MAJOR 1
	CACHE STRING "Major version number of this build.")
set(CATENA_VERSION_MINOR 0
	CACHE STRING "Minor version number of this build.")

set(CATENA_EDITOR "../CatenaEd/"
	CACHE PATH "Path to the editor/tools directory.")
set(CATENA_OUTPUT "../Build/"
	CACHE PATH "Path to the intermediate files produced during compilation and linking.")
set(CATENA_DEPS "../Dependencies/"
	CACHE PATH "Path to the dependencies (required to build Catena).")
	
set(CATENA_DEPNAME_RESOURCES "resources"
	CACHE PATH "Name of the used resources dependency folder.")
set(CATENA_DEPNAME_SWIG "swigwin-3.0.0"
	CACHE STRING "Name of the used swig dependency folder.")
		
set(CATENA_LAUNCHER_NAME "Launcher"
	CACHE STRING "Name of the final launcher.")
set(CATENA_LAUNCHER_ALLINONE 1
	CACHE BOOL "Try to make an all in one executable (use static libraries).")
set(CATENA_LAUNCHER_SUPPORT_D3D9 1
	CACHE BOOL "Enable support for d3d9.")
set(CATENA_LAUNCHER_SUPPORT_D3D11 1
	CACHE BOOL "Enable support for d3d11.")
set(CATENA_LAUNCHER_SUPPORT_OPENGL 1
	CACHE BOOL "Enable support for opengl.")

if(EXISTS ${CATENA_OUTPUT})
	set(CATENA_OUTPUT_FULL ${CATENA_OUTPUT})
else()
	set(CATENA_OUTPUT_FULL ${CMAKE_PROJECT_SOURCE_DIR}/${CATENA_OUTPUT})
endif()

if(EXISTS ${CATENA_DEPS})
	set(CATENA_DEPS_FULL ${CATENA_DEPS})
else()
	set(CATENA_DEPS_FULL ${CMAKE_PROJECT_SOURCE_DIR}/${CATENA_DEPS}/${BUILD_TYPE})
endif()

if(EXISTS ${CATENA_DEPNAME_SWIG})
	set(SWIG_DIR "${CATENA_DEPNAME_SWIG}")
else()
	set(SWIG_DIR "${CATENA_DEPS_FULL}/${CATENA_DEPNAME_SWIG}")
endif()

if(EXISTS ${CATENA_DEPNAME_RESOURCES})
	set(RESOURCES_DIR "${CATENA_DEPNAME_RESOURCES}")
else()
	set(RESOURCES_DIR "${CATENA_DEPS_FULL}/${CATENA_DEPNAME_RESOURCES}")
endif()

if(WIN32 AND CATENA_LAUNCHER_SUPPORT_D3D9)
	set(WITH_D3D9 1)
	add_definitions(-D_WITH_D3D9)
endif()

if(WIN32 AND CATENA_LAUNCHER_SUPPORT_D3D11)
	set(WITH_D3D11 1)
	add_definitions(-D_WITH_D3D11)
endif()

if(CATENA_LAUNCHER_SUPPORT_OPENGL)
	set(WITH_OPENGL 1)
	add_definitions(-D_WITH_OPENGL)
endif()

set(SWIG_BIN "${SWIG_DIR}/swig.exe")
set(CMAKE_INSTALL_PREFIX ${CATENA_OUTPUT_FULL})
