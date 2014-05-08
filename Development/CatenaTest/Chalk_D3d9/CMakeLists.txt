
set(CHALK_D3D9_FILES_HEADER
	inc/Chalk_D3d9.h
	inc/Chalk_D3d9_Std.h
	inc/Chalk_D3d9_Defines.h
	inc/Chalk_D3d9_Device.h
	inc/Chalk_D3d9_Shader.h
	inc/Chalk_D3d9_VertexBuffer.h
	inc/Chalk_D3d9_IndexBuffer.h
)

set(CHALK_D3D9_FILES_SOURCE
	src/Std.cpp
	src/Device.cpp
	src/Shader.cpp
	src/VertexBuffer.cpp
	src/IndexBuffer.cpp
)

component_init()

include_directories("${ROCK_INCLUDE_DIR}")
include_directories("${CHALK_INCLUDE_DIR}")
include_directories("${CHALK_D3D9_INCLUDE_DIR}")

add_library(Chalk_d3d9Lib STATIC ${CHALK_D3D9_FILES_HEADER} ${CHALK_D3D9_FILES_SOURCE})
add_dependencies(Chalk_d3d9Lib RockLib ChalkLib)

add_library(Chalk_d3d9 SHARED ${CHALK_D3D9_FILES_HEADER} ${CHALK_D3D9_FILES_SOURCE})
add_dependencies(Chalk_d3d9 RockLib ChalkLib)
