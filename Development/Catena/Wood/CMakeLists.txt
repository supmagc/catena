
set(WOOD_FILES_HEADER
	inc/Wood.h
	inc/Wood_Std.h
	inc/Wood_Defines.h
	inc/Wood_IMainLoop.h
	inc/Wood_IWindow.h
)

set(WOOD_FILES_SOURCE
	src/Std.cpp
)

component_init()
add_component("Wood" "Rock;Diamond" ${WOOD_FILES_HEADER} ${WOOD_FILES_SOURCE})
