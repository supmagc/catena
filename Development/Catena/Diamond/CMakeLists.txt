
set(DIAMOND_FILES_HEADER
    inc/Diamond.h
    inc/Diamond_Std.h
    inc/Diamond_Defines.h
    inc/Diamond_Core.h
    inc/Diamond_Scene.h
    inc/Diamond_Renderer.h
    inc/Diamond_ICanvas.h
    inc/Diamond_IViewer.h
    inc/Diamond_WindowCanvas.h
    inc/Diamond_InteractiveViewer.h
    inc/Diamond_Mesh.h

    inc/Diamond_SceneView.h
)

set(DIAMOND_FILES_SOURCE
    src/Std.cpp
    src/Core.cpp
    src/Scene.cpp
    src/Renderer.cpp
    src/WindowCanvas.cpp
    src/InteractiveViewer.cpp
    src/Mesh.cpp

    src/SceneView.cpp
)

component_init()
add_component("Diamond" "Rock;Chalk" ${DIAMOND_FILES_HEADER} ${DIAMOND_FILES_SOURCE})

if(WITH_D3D9)
    message(STATUS "Compiling Diamond with D3D9 support.")
    add_component_dependencies(Diamond Chalk_D3d9)
endif()
