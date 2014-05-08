
function(add_component COMP_NAME COMP_INC_STATIC, COMP_INC_SHARED)
	include_directories(${CATENA_SOURCE_DIR}/${COMP_NAME}/inc/)
endfunction()

function(set_precompiled_header TARGET HEADER_FILE SRC_FILE)
	get_filename_component(HEADER ${HEADER_FILE} NAME)
	if(MSVC AND NOT NMAKE)
		add_definitions(/Yu"${HEADER}")
		set_source_files_properties(${SRC_FILE}
			PPROPERTIES COMPILE_FLAGS /Yc"${HEADER}"
	)
	endif ()
endfunction()

#
# Define the basic properties and capabilities of each component
# - COMP_NAME The name of the component-directory
# - COMP_EXE Define if this component should be compiled as executable
# - COMP_STATIC Define if this component should be compiled as static library
# - COMP_SHARED Define if this component should be compiled as shared library
function(define_component COMP_NAME COMP_EXE COMP_STATIC COMP_SHARED)
	string(TOUPPER ${COMP_NAME} COMP_NAME_UPPER)
	
	if(${COMP_EXE})
		set(${COMP_NAME_UPPER}_BUILD_EXE PARENT_SCOPE)
	endif()
	if(${COMP_STATIC})
		set(${COMP_NAME_UPPER}_BUILD_STATIC PARENT_SCOPE)
	endif()
	if(${COMP_SHARED})
		set(${COMP_NAME_UPPER}_BUILD_SHARED PARENT_SCOPE)
	endif()
	
	set(${COMP_NAME_UPPER}_NAME ${COMP_NAME} PARENT_SCOPE)
	set(${COMP_NAME_UPPER}_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/${COMP_NAME}/inc/ PARENT_SCOPE)
endfunction()

function(add_component COMP_NAME COMP_DEPS COMP_FILES)
	string(TOUPPER ${COMP_NAME} COMP_NAME_UPPER)

	if(${COMP_NAME_UPPER}_BUILD_EXE)
		add_executable(${COMP_NAME} COMP_FILES)
	endif()
	if(${COMP_NAME_UPPER}_BUILD_STATIC)
		add_library(${COMP_NAME} STATIC COMP_FILES)
	endif()
	if(${COMP_NAME_UPPER}_BUILD_SHARED)
		add_library(${COMP_NAME} SHARED COMP_FILES)
	endif()

	add_component_dependencies(${COMP_NAME} ${COMP_DEPS})
endfunction()

function(add_component_dependencies COMP_NAME COMP_DEPS)
	string(TOUPPER ${COMP_NAME} COMP_NAME_UPPER)

	foreach(COMP_DEP_NAME ${COMP_DEPS})
		string(TOUPPER ${COMP_DEP_NAME} COMP_DEP_NAME_UPPER)

		include_directories(${${COMP_DEP_NAME_UPPER}_INCLUDE_DIR})

		if(${COMP_NAME}_BUILD_EXE)
			if(${COMP_NAME}_BUILD_STATIC)
				add_dependencies(${COMP_NAME} ${COMP_DEP_NAME}Lib)
			endif()
			if(${COMP_NAME}_BUILD_SHARED)
				add_dependencies(${COMP_NAME} ${COMP_DEP_NAME})
			endif()
		endif()
		if(${COMP_NAME}_BUILD_STATIC)
			if(${COMP_NAME}_BUILD_STATIC)
				add_dependencies(${COMP_NAME}Lib ${COMP_DEP_NAME}Lib)
			endif()
			if(${COMP_NAME}_BUILD_SHARED)
				add_dependencies(${COMP_NAME}Lib ${COMP_DEP_NAME})
			endif()
		endif()
		if(${COMP_NAME}_BUILD_SHARED)
			if(${COMP_NAME}_BUILD_SHARED)
				add_dependencies(${COMP_NAME} ${COMP_DEP_NAME})
			endif()
			if(${COMP_NAME}_BUILD_STATIC)
				add_dependencies(${COMP_NAME} ${COMP_DEP_NAME}Lib)
			endif()
		endif()
	endforeach()
endfunction()