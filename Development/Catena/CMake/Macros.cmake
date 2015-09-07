
macro(component_init)
	source_group("CMake Files" FILES CMakeLists.txt)
	source_group("Inline Files" REGULAR_EXPRESSION ".*\\.inl$")
	source_group("Swig Files" REGULAR_EXPRESSION ".*_swig(_wrap)?\\.(i|cxx)$")
endmacro()

macro(component_verify)
	string(TOUPPER ${${ARGV0}} ${ARGV1})
	string(TOLOWER ${${ARGV0}} ${ARGV2})
	if(NOT ${${ARGV1}}_NAME)
		message("Component ${ARGV0} is not defined.")
		return()
	endif()
endmacro()

macro(component_helper)
	set(${COMP_NAME_UPPER}_NAME ${COMP_NAME} PARENT_SCOPE)
	set(${COMP_NAME_UPPER}_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/${COMP_NAME}/inc/ PARENT_SCOPE)
endmacro()

macro(boost_init)
	find_package(Boost 1.59.0 REQUIRED COMPONENTS ${BOOST_LIBRARIES})
endmacro()