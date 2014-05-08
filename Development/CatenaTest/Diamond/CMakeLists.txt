
set(DIAMOND_FILES_HEADER
	inc/Diamond.h
	inc/Diamond_Std.h
	inc/Diamond_Defines.h
	inc/Diamond_Core.h
)

set(DIAMOND_FILES_SOURCE
	src/Std.cpp
	src/Core.cpp
)

component_init()

include_directories("${ROCK_INCLUDE_DIR}")
include_directories("${CHALK_INCLUDE_DIR}")
include_directories("${DIAMOND_INCLUDE_DIR}")

add_library(DiamondLib STATIC ${DIAMOND_FILES_HEADER} ${DIAMOND_FILES_SOURCE})
add_dependencies(DiamondLib RockLib ChalkLib)

add_library(Diamond SHARED ${DIAMOND_FILES_HEADER} ${DIAMOND_FILES_SOURCE})
add_dependencies(Diamond Rock ChalkLib)
set_target_properties(Diamond PROPERTIES
	COMPILE_DEFINITIONS ROCK_IMPORTS
)

if(WITH_D3D9)
	add_component_dependencies(Diamond Chalk_D3d9)
endif()
