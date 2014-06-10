
set(CHALK_D3D9_FILES_HEADER
    inc/Chalk_D3d9.h
    inc/Chalk_D3d9_Std.h
    inc/Chalk_D3d9_Defines.h
    inc/Chalk_D3d9_Device.h
    inc/Chalk_D3d9_Shader.h
    inc/Chalk_D3d9_VertexBuffer.h
    inc/Chalk_D3d9_IndexBuffer.h
    inc/Chalk_D3d9_SwapChain.h
)

set(CHALK_D3D9_FILES_SOURCE
    src/Std.cpp
    src/Device.cpp
    src/Shader.cpp
    src/VertexBuffer.cpp
    src/IndexBuffer.cpp
    src/SwapChain.cpp
)

component_init()
add_component("Chalk_D3d9" "Rock;Chalk" ${CHALK_D3D9_FILES_HEADER} ${CHALK_D3D9_FILES_SOURCE})
add_component_dependency_extern("Chalk_D3d9" "" "d3d9")
add_component_dependency_extern("Chalk_D3d9" "" "d3dcompiler")
