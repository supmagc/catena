cmake_minimum_required(VERSION 2.8)

project("Catena")

list(APPEND CMAKE_MODULE_PATH "${Catena_SOURCE_DIR}/CMake")

include("BuildProperties")
include("Configuration")
include("Functions")
include("Macros")

define_component(Rock 0 1 1)
define_component(Chalk 0 1 0)
define_component(Chalk_D3d9 0 1 1)
define_component(Chalk_D3d11 0 1 1)
define_component(Chalk_OpenGl 0 1 1)
define_component(Diamond 0 1 1)
define_component(Wood 0 1 0)
define_component(Wood_Windows 0 1 1)
define_component(Wood_Launcher 1 0 0)

add_subdirectory("Rock")
add_subdirectory("Diamond")
add_subdirectory("Chalk")

if(CATENA_LAUNCHER_SUPPORT_D3D9)
	add_subdirectory("Chalk_d3d9")
endif()
if(CATENA_LAUNCHER_SUPPORT_D3D11)
	add_subdirectory("Chalk_d3d11")
endif()
if(CATENA_LAUNCHER_SUPPORT_OPENGL)
	add_subdirectory("Chalk_OpenGl")
endif()
