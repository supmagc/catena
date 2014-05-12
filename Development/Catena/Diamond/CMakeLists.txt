
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
add_component("Diamond" "Rock;Chalk" ${DIAMOND_FILES_HEADER} ${DIAMOND_FILES_SOURCE})

if(WITH_D3D9)
	message(STATUS "Compiling Diamond with D3D9 support.")
	add_component_dependencies(Diamond Chalk_D3d9)
endif()
