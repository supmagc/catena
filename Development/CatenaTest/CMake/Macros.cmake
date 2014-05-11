
macro(component_init)
	source_group("CMake Files" FILES CMakeLists.txt)
	source_group("Inline Files" REGULAR_EXPRESSION ".*\\.inl$")
endmacro()

macro(component_verify)
	string(TOUPPER ${${ARGV0}} ${ARGV1})
	if(NOT ${${ARGV1}}_NAME)
		message("Component ${ARGV0} is not defined.")
		return()
	endif()
endmacro()

macro(component_helper)
	set(${COMP_NAME_UPPER}_NAME ${COMP_NAME} PARENT_SCOPE)
	set(${COMP_NAME_UPPER}_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/${COMP_NAME}/inc/ PARENT_SCOPE)
endmacro()
