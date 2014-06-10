
set(CHALK_FILES_HEADER
	inc/Chalk.h
	inc/Chalk_Std.h
	inc/Chalk_Types.h
	inc/Chalk_Defines.h
	inc/Chalk_IDevice.h
	inc/Chalk_IShader.h
	inc/Chalk_IVertexBuffer.h
	inc/Chalk_IIndexBuffer.h
	inc/Chalk_ISwapChain.h
)

set(CHALK_FILES_SOURCE
	src/Std.cpp
)

component_init()
add_component("Chalk" "Rock" ${CHALK_FILES_HEADER} ${CHALK_FILES_SOURCE})
