
set(ROCK_FILES_HEADER
    inc/Rock.h
    inc/Rock_Std.h
    inc/Rock_Defines.h
    inc/Rock_Types.h
    inc/Rock_String.h
    inc/Rock_Log.h
    inc/Rock_Checks.h
    inc/Rock_Functions.h
    inc/Rock_Matrix4x4.h
    inc/Rock_Vector4.h
    inc/Rock_Vector3.h
    inc/Rock_Vector2.h
    inc/Rock_Array.h
    inc/Rock_Memory.h
)

set(ROCK_FILES_INLINE
    inl/Matrix4x4.inl
    inl/Vector4.inl
    inl/Vector3.inl
    inl/Vector2.inl
    inl/Array.inl
)

set(ROCK_FILES_SOURCE
    src/Std.cpp
    src/Matrix4x4.cpp
    src/Vector4.cpp
    src/Vector3.cpp
    src/Vector2.cpp
    src/String.cpp
    src/Log.cpp
    src/Functions.cpp
    src/Array.cpp
    src/Memory.cpp
)

component_init()
add_component("Rock" "" ${ROCK_FILES_HEADER} ${ROCK_FILES_INLINE} ${ROCK_FILES_SOURCE})
