
set(WOOD_WINDOWS_FILES_HEADER
	inc/Wood_Windows.h
	inc/Wood_Windows_Std.h
	inc/Wood_Windows_Defines.h
	inc/Wood_Windows_WindowMain.h
)

set(WOOD_WINDOWS_FILES_SOURCE
	src/Std.cpp
	src/WindowMain.cpp
)

component_init()
add_component("Wood_Windows" "Rock;Diamond;Wood" ${WOOD_WINDOWS_FILES_HEADER} ${WOOD_WINDOWS_FILES_SOURCE})
