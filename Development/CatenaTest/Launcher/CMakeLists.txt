
set(LAUNCHER_FILES_HEADER
	inc/Launcher_Std.h
	inc/Resources.h
)

set(LAUNCHER_FILES_RESOURCE
	res/Resources.rc
	res/Resources.aps
	res/RCa00464
	res/cursor.cur
	res/icon_large.ico
	res/icon_small.ico
	res/splash.bmp
)

set(LAUNCHER_FILES_SOURCE
	src/Std.cpp
	src/Main.cpp
)

component_init()
add_component("Launcher" "Rock;Wood;Wood_Windows" ${LAUNCHER_FILES_HEADER} ${LAUNCHER_FILES_RESOURCE} ${LAUNCHER_FILES_SOURCE})
