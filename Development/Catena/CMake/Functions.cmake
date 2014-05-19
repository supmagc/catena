
function(add_component COMP_NAME COMP_INC_STATIC, COMP_INC_SHARED)
	include_directories(${CATENA_SOURCE_DIR}/${COMP_NAME}/inc/)
endfunction()

function(target_precompiled_header COMP_NAME HEADER_FILE SOURCE_FILE)
	get_filename_component(HEADER ${HEADER_FILE} NAME)
	if(MSVC AND NOT NMAKE)
		add_definitions(/Yu"${HEADER}")
		set_source_files_properties(${SOURCE_FILE}
			PPROPERTIES COMPILE_FLAGS /Yc"${HEADER}"
		)
	endif ()
endfunction()

function(define_component_executable COMP_NAME COMP_ALLINONE)
	string(TOUPPER ${COMP_NAME} COMP_NAME_UPPER)
	set(${COMP_NAME_UPPER}_BUILD_EXE 1 PARENT_SCOPE)
	if(COMP_ALLINONE)
		set(${COMP_NAME_UPPER}_BUILD_ALLINONE 1 PARENT_SCOPE)
	endif()
	component_helper()
endfunction()

function(define_component_library COMP_NAME COMP_SHARED)
	string(TOUPPER ${COMP_NAME} COMP_NAME_UPPER)
	set(${COMP_NAME_UPPER}_BUILD_STATIC 1 PARENT_SCOPE)
	if(COMP_SHARED)
		set(${COMP_NAME_UPPER}_BUILD_SHARED 1 PARENT_SCOPE)
	endif()
	component_helper()
endfunction()

function(add_component COMP_NAME COMP_DEPS COMP_FILES)
	component_verify(COMP_NAME COMP_NAME_UPPER COMP_NAME_LOWER)
	list(APPEND COMP_FILES ${ARGN})

	if(${COMP_NAME_UPPER}_BUILD_EXE)
		message(STATUS "Building ${COMP_NAME} as executable.")
		add_executable(${COMP_NAME} WIN32 ${COMP_FILES})
		if(MSVC AND MSVC_VERSION GREATER 1600)
			set(CATENA_VCXPROJ_USER_CWDDIR $(OutDir))
			configure_file(
				${CMAKE_PROJECT_SOURCE_DIR}/CMake/Project.vcxproj.user.in
				${CMAKE_CURRENT_BINARY_DIR}/${COMP_NAME}.vcxproj.user
			)
		endif()
		target_include_directories(${COMP_NAME} PUBLIC ${${COMP_NAME_UPPER}_INCLUDE_DIR})
		target_precompiled_header(${COMP_NAME} inc/${COMP_NAME}_Std.h src/Std.cpp)
	endif()
	if(${COMP_NAME_UPPER}_BUILD_STATIC)
		message(STATUS "Building ${COMP_NAME} as static library.")
		add_library(${COMP_NAME}_Lib STATIC ${COMP_FILES})
		target_include_directories(${COMP_NAME}_Lib PUBLIC ${${COMP_NAME_UPPER}_INCLUDE_DIR})
		target_precompiled_header(${COMP_NAME}_Lib inc/${COMP_NAME}_Std.h src/Std.cpp)
	endif()
	if(${COMP_NAME_UPPER}_BUILD_SHARED)
		message(STATUS "Building ${COMP_NAME} as shared library.")
		set(SWIG_INTERFACE "${CMAKE_PROJECT_SOURCE_DIR}/${COMP_NAME}/swig/${COMP_NAME_LOWER}_swig.i")
		set(SWIG_WRAPPER "${CMAKE_PROJECT_SOURCE_DIR}/${COMP_NAME}/swig/${COMP_NAME_LOWER}_swig_wrap.cxx")
		set(SWIG_OUTPUT "${CMAKE_PROJECT_SOURCE_DIR}/${CATENA_EDITOR}/swig-csharp/${COMP_NAME}")
		if(EXISTS "${SWIG_INTERFACE}")
			if(NOT EXISTS "${SWIG_OUTPUT}")
				file(MAKE_DIRECTORY "${SWIG_OUTPUT}")
			endif()
			list(APPEND COMP_FILES "swig/${COMP_NAME_LOWER}_swig.i")
			if(EXISTS ${SWIG_WRAPPER})
				list(APPEND COMP_FILES "swig/${COMP_NAME_LOWER}_swig_wrap.cxx")
			endif()
		endif()
		add_library(${COMP_NAME}_Shared SHARED ${COMP_FILES})
		target_include_directories(${COMP_NAME}_Shared PUBLIC ${${COMP_NAME_UPPER}_INCLUDE_DIR})
		target_precompiled_header(${COMP_NAME}_Shared inc/${COMP_NAME}_Std.h src/Std.cpp)
		if(EXISTS ${SWIG_INTERFACE})
			add_custom_command(
				OUTPUT "${SWIG_INTERFACE}"
				COMMAND "${SWIG_BIN}" -c++ -csharp -namespace ${COMP_NAME} -o "${SWIG_WRAPPER}" -outdir "${SWIG_OUTPUT}" "${SWIG_INTERFACE}"
				WORKING_DIRECTORY "${CMAKE_PROJECT_SOURCE_DIR}/${COMP_NAME}"
			)
		endif()
		target_compile_definitions(${COMP_NAME}_Shared 
			INTERFACE -D${COMP_NAME_UPPER}_IMPORTS
			PRIVATE -D${COMP_NAME_UPPER}_EXPORTS
		)
		unset(COMP_SWIG_INTERFACE CACHE)
		unset(COMP_SWIG_WRAPPER CACHE)
	endif()

	if(COMP_DEPS)
		add_component_dependencies("${COMP_NAME}" "${COMP_DEPS}")
	endif()
endfunction()

function(add_component_dependencies COMP_NAME COMP_DEPS)
	component_verify(COMP_NAME COMP_NAME_UPPER COMP_NAME_LOWER)

	foreach(COMP_DEP_NAME ${COMP_DEPS})
		component_verify(COMP_DEP_NAME COMP_DEP_NAME_UPPER COMP_DEP_NAME_LOWER)

		if(${COMP_NAME_UPPER}_BUILD_EXE)
			if(${COMP_NAME_UPPER}_BUILD_ALLINONE)
				if(${COMP_DEP_NAME_UPPER}_BUILD_STATIC)
					target_link_libraries(${COMP_NAME} PRIVATE ${COMP_DEP_NAME}_Lib)
				elseif(${COMP_DEP_NAME_UPPER}_BUILD_SHARED)
					target_link_libraries(${COMP_NAME} PRIVATE ${COMP_DEP_NAME}_Shared)
				endif()
			else()
				if(${COMP_DEP_NAME_UPPER}_BUILD_SHARED)
					target_link_libraries(${COMP_NAME} PRIVATE ${COMP_DEP_NAME}_Shared)
				elseif(${COMP_DEP_NAME_UPPER}_BUILD_STATIC)
					target_link_libraries(${COMP_NAME} PRIVATE ${COMP_DEP_NAME}_Lib)
				endif()
			endif()
		endif()
		if(${COMP_NAME_UPPER}_BUILD_STATIC)
			if(${COMP_DEP_NAME_UPPER}_BUILD_STATIC)
				target_link_libraries(${COMP_NAME}_Lib PRIVATE ${COMP_DEP_NAME}_Lib)
			elseif(${COMP_DEP_NAME_UPPER}_BUILD_SHARED)
				message(WARNING "Static library ${COMP_NAME} shouldn't depend on dynamic library ${COMP_DEP_NAME}")
			endif()
		endif()
		if(${COMP_NAME_UPPER}_BUILD_SHARED)
			if(${COMP_DEP_NAME_UPPER}_BUILD_SHARED)
				target_link_libraries(${COMP_NAME}_Shared PUBLIC ${COMP_DEP_NAME}_Shared)
			elseif(${COMP_DEP_NAME_UPPER}_BUILD_STATIC)
				target_link_libraries(${COMP_NAME}_Shared PUBLIC ${COMP_DEP_NAME}_Lib)
			endif()
		endif()
	endforeach()
endfunction()

function(add_component_dependency_extern COMP_NAME DEP_INCLUDE DEP_LIBRARY)
	component_verify(COMP_NAME COMP_NAME_UPPER COMP_NAME_LOWER)

	if(DEP_INCLUDE)
		if(${COMP_NAME_UPPER}_BUILD_EXE)
			target_include_directories(${COMP_NAME} PRIVATE ${DEP_INCLUDE})
		endif()
		if(${COMP_NAME_UPPER}_BUILD_STATIC)
			target_include_directories(${COMP_NAME}_Lib PRIVATE ${DEP_INCLUDE})
		endif()
		if(${COMP_NAME_UPPER}_BUILD_SHARED)
			target_include_directories(${COMP_NAME}_Shared PRIVATE ${DEP_INCLUDE})
		endif()
	endif()

	if(DEP_LIBRARY)
		if(${COMP_NAME_UPPER}_BUILD_EXE)
			message(STATUS "Closed linking added for ${COMP_NAME}: ${DEP_LIBRARY}")
			target_link_libraries(${COMP_NAME} PRIVATE ${DEP_LIBRARY})
		endif()
		if(${COMP_NAME_UPPER}_BUILD_STATIC)
			message(STATUS "Closed linking added for ${COMP_NAME}_Lib: ${DEP_LIBRARY}b")
			target_link_libraries(${COMP_NAME}_Lib PRIVATE ${DEP_LIBRARY})
		endif()
		if(${COMP_NAME_UPPER}_BUILD_SHARED)
			message(STATUS "Closed linking added for ${COMP_NAME}_Shared: ${DEP_LIBRARY}")
			target_link_libraries(${COMP_NAME}_Shared PRIVATE ${DEP_LIBRARY})
		endif()
	endif()
endfunction()