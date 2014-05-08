
set(CHALK_FILES_HEADER
	inc/Chalk.h
	inc/Chalk_Std.h
	inc/Chalk_Defines.h
	inc/Chalk_IDevice.h
	inc/Chalk_IShader.h
	inc/Chalk_IVertexBuffer.h
	inc/Chalk_IIndexBuffer.h
)

set(CHALK_FILES_SOURCE
	src/Std.cpp
)

component_init()

include_directories("${ROCK_INCLUDE_DIR}")
include_directories("${CHALK_INCLUDE_DIR}")

add_library(ChalkLib STATIC ${CHALK_FILES_HEADER} ${CHALK_FILES_SOURCE})
add_dependencies(ChalkLib RockLib)
