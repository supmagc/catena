
set(ROCK_FILES_HEADER
    inc/Rock.h
    inc/Rock_Std.h
    inc/Rock_Defines.h
    inc/Rock_Types.h
    inc/Rock_String.h
    inc/Rock_StringBuilder.h
    inc/Rock_Log.h
    inc/Rock_Checks.h
    inc/Rock_Functions.h
    inc/Rock_Matrix.h
    inc/Rock_Vector.h
    inc/Rock_Array.h
    inc/Rock_Memory.h
    inc/Rock_Allocators.h
	inc/Rock_Console.h
)

set(ROCK_FILES_INLINE
    inl/Matrix.inl
    inl/Vector.inl
    inl/Functions.inl
)

set(ROCK_FILES_SOURCE
    src/Std.cpp
    src/String.cpp
    src/StringBuilder.cpp
    src/Log.cpp
    src/Functions.cpp
    src/Array.cpp
    src/Memory.cpp
    src/Allocators.cpp
	src/Console.cpp
)

set(ROCK_FILES_TEST
    test/old.cpp
	test/Driver.cpp
	test/StringTest.cpp
	test/StringBuilderTest.cpp
	test/VectorTest.cpp
	test/MatrixTest.cpp
)

component_init()
add_component("Rock" "" ${ROCK_FILES_HEADER} ${ROCK_FILES_INLINE} ${ROCK_FILES_SOURCE} ${ROCK_FILES_TEST})
