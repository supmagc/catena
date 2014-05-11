cmake_minimum_required(VERSION 2.8)

project("Catena")

list(APPEND CMAKE_MODULE_PATH "${Catena_SOURCE_DIR}/CMake")

include("Configuration")
include("BuildProperties")
include("Functions")
include("Macros")

define_component_library(Rock 1)
define_component_library(Chalk 0)
define_component_library(Chalk_D3d9 1)
define_component_library(Chalk_D3d11 1)
define_component_library(Chalk_OpenGl 1)
define_component_library(Diamond 1)
define_component_library(Wood 0)
define_component_library(Wood_Windows 0)
define_component_executable(Launcher ${CATENA_LAUNCHER_ALLINONE})

add_subdirectory("Rock")
add_subdirectory("Chalk")

if(WITH_D3D9)
	add_subdirectory("Chalk_d3d9")
endif()
if(WITH_D3D11)
	add_subdirectory("Chalk_d3d11")
endif()
if(WITH_OPENGL)
	add_subdirectory("Chalk_OpenGl")
endif()

add_subdirectory("Diamond")
add_subdirectory("Wood")
add_subdirectory("Wood_Windows")
add_subdirectory("Launcher")
