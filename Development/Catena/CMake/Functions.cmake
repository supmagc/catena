
function(target_precompiled_header COMP_NAME HEADER_FILE SOURCE_FILE IGNORE_FILES)
	list(APPEND IGNORE_FILES ${ARGN})
	get_filename_component(HEADER ${HEADER_FILE} NAME)
	if(MSVC AND NOT NMAKE)
		add_definitions(/Yu"${HEADER}")
		set_source_files_properties(${SOURCE_FILE}
			PROPERTIES COMPILE_FLAGS /Yc"${HEADER}"
		)
		foreach(IGNORE_FILE ${IGNORE_FILES})
			set_source_files_properties(${IGNORE_FILE}
				PROPERTIES COMPILE_FLAGS /Y-
			)
		endforeach()
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

function(define_component_library COMP_NAME COMP_SHARED COMP_TEST)
	string(TOUPPER ${COMP_NAME} COMP_NAME_UPPER)
	set(${COMP_NAME_UPPER}_BUILD_STATIC 1 PARENT_SCOPE)
	if(COMP_SHARED)
		set(${COMP_NAME_UPPER}_BUILD_SHARED 1 PARENT_SCOPE)
	endif()
	if(COMP_TEST)
		set(${COMP_NAME_UPPER}_BUILD_TEST 1 PARENT_SCOPE)
	endif()
	component_helper()
endfunction()

function(define_boost_library COMP_NAME)
	string(TOUPPER ${COMP_NAME} COMP_NAME_UPPER)
	set(${COMP_NAME_UPPER}_BOOST 1 PARENT_SCOPE)
	set(${COMP_NAME_UPPER}_NAME ${COMP_NAME} PARENT_SCOPE)
	list(APPEND BOOST_LIBRARIES ${COMP_NAME})
	set(BOOST_LIBRARIES "${BOOST_LIBRARIES}" PARENT_SCOPE)
endfunction()

function(install_component COMP_NAME_FULL)
	if(${COMP_NAME_FULL} MATCHES "TestDriver$")
	message(STATUS "-- Creating install for ${COMP_NAME_FULL}")
		install(TARGETS ${COMP_NAME_FULL}
			CONFIGURATIONS Debug
			DESTINATION Debug/tests
		)	
		install(TARGETS ${COMP_NAME_FULL}
			CONFIGURATIONS Release
			DESTINATION Release/tests
		)	
		install(TARGETS ${COMP_NAME_FULL}
			CONFIGURATIONS Publish
			DESTINATION Publish/tests
		)	
	else()
		install(TARGETS ${COMP_NAME_FULL}
			CONFIGURATIONS Debug
			RUNTIME DESTINATION Debug/bin
			LIBRARY DESTINATION Debug/bin
			ARCHIVE DESTINATION Debug/lib
		)	
		install(TARGETS ${COMP_NAME_FULL}
			CONFIGURATIONS Release
			RUNTIME DESTINATION Release/bin
			LIBRARY DESTINATION Release/bin
			ARCHIVE DESTINATION Release/lib
		)	
		install(TARGETS ${COMP_NAME_FULL}
			CONFIGURATIONS Publish
			RUNTIME DESTINATION Publish/bin
			LIBRARY DESTINATION Publish/bin
			ARCHIVE DESTINATION Publish/lib
		)	
	endif()
endfunction()

function(add_component COMP_NAME COMP_DEPS COMP_FILES)
	component_verify(COMP_NAME COMP_NAME_UPPER COMP_NAME_LOWER)
	list(APPEND COMP_FILES ${ARGN})
	set(COMP_FILES_BUILD)
	set(COMP_FILES_TEST)
	
	foreach(COMP_FILE ${COMP_FILES})
		if(${COMP_FILE} MATCHES "^test/")
			list(APPEND COMP_FILES_TEST ${COMP_FILE})
		else()
			list(APPEND COMP_FILES_BUILD ${COMP_FILE})
		endif()
	endforeach()
	
	if(${COMP_NAME_UPPER}_BUILD_EXE)
		message(STATUS "Building ${COMP_NAME} as executable.")
		add_executable(${COMP_NAME} WIN32 ${COMP_FILES_BUILD})
		if(MSVC AND MSVC_VERSION GREATER 1600)
			set(CATENA_VCXPROJ_USER_CWDDIR $(OutDir))
			configure_file(
				${CMAKE_PROJECT_SOURCE_DIR}/CMake/Project.vcxproj.user.in
				${CMAKE_CURRENT_BINARY_DIR}/${COMP_NAME}.vcxproj.user
			)
		endif()
		set_target_properties(${COMP_NAME} PROPERTIES FOLDER ${COMP_NAME})
		target_include_directories(${COMP_NAME} PUBLIC ${${COMP_NAME_UPPER}_INCLUDE_DIR})
		target_precompiled_header(${COMP_NAME} inc/${COMP_NAME}_Std.h src/Std.cpp "" ${COMP_FILES_TEST})
		install_component(${COMP_NAME})
	endif()
	
	if(${COMP_NAME_UPPER}_BUILD_STATIC)
		message(STATUS "Building ${COMP_NAME} as static library.")
		add_library(${COMP_NAME}_Lib STATIC ${COMP_FILES_BUILD})
		set_target_properties(${COMP_NAME}_Lib PROPERTIES FOLDER ${COMP_NAME})
		target_include_directories(${COMP_NAME}_Lib PUBLIC ${${COMP_NAME_UPPER}_INCLUDE_DIR})
		target_precompiled_header(${COMP_NAME}_Lib inc/${COMP_NAME}_Std.h src/Std.cpp "" ${COMP_FILES_TEST})
		install_component(${COMP_NAME}_Lib)
	endif()
	
	if(${COMP_NAME_UPPER}_BUILD_SHARED)
		message(STATUS "Building ${COMP_NAME} as shared library.")
		set(SWIG_INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/swig/${COMP_NAME_LOWER}_swig.i")
		set(SWIG_WRAPPER "${CMAKE_CURRENT_SOURCE_DIR}/swig/${COMP_NAME_LOWER}_swig_wrap.cxx")
		set(SWIG_OUTPUT "${CMAKE_PROJECT_SOURCE_DIR}/${CATENA_EDITOR}/CatenaCSharp/${COMP_NAME}")
		if(EXISTS "${SWIG_INTERFACE}")
			if(NOT EXISTS "${SWIG_OUTPUT}")
				file(MAKE_DIRECTORY "${SWIG_OUTPUT}")
			endif()
			list(APPEND COMP_FILES_BUILD "swig/${COMP_NAME_LOWER}_swig.i")
			list(APPEND COMP_FILES_BUILD "swig/${COMP_NAME_LOWER}_swig_wrap.cxx")
		endif()
		add_library(${COMP_NAME}_Shared SHARED ${COMP_FILES_BUILD})
		set_target_properties(${COMP_NAME}_Shared PROPERTIES FOLDER ${COMP_NAME})
		target_include_directories(${COMP_NAME}_Shared PUBLIC ${${COMP_NAME_UPPER}_INCLUDE_DIR})
		target_precompiled_header(${COMP_NAME}_Shared inc/${COMP_NAME}_Std.h src/Std.cpp "swig/${COMP_NAME_LOWER}_swig_wrap.cxx" ${COMP_FILES_TEST})
		if(EXISTS "${SWIG_INTERFACE}")
			add_custom_command(
				OUTPUT "${SWIG_WRAPPER}"
				COMMAND "${SWIG_BIN}" -c++ -csharp -namespace ${COMP_NAME} -outdir "${SWIG_OUTPUT}" "${SWIG_INTERFACE}"
				WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
			)
		endif()
		target_compile_definitions(${COMP_NAME}_Shared 
			INTERFACE -D${COMP_NAME_UPPER}_IMPORTS
			PRIVATE -D${COMP_NAME_UPPER}_EXPORTS
		)
		unset(COMP_SWIG_INTERFACE CACHE)
		unset(COMP_SWIG_WRAPPER CACHE)
		install_component(${COMP_NAME}_Shared)
	endif()

	if(COMP_DEPS)
		add_component_dependencies("${COMP_NAME}" "${COMP_DEPS}")
	endif()

	if(${COMP_NAME_UPPER}_BUILD_TEST)
		add_component_test("${COMP_NAME}" "${COMP_FILES_TEST}")
	endif()
endfunction()

function(add_component_dependencies COMP_NAME COMP_DEPS)
	component_verify(COMP_NAME COMP_NAME_UPPER COMP_NAME_LOWER)

	foreach(COMP_DEP_NAME ${COMP_DEPS})
		component_verify(COMP_DEP_NAME COMP_DEP_NAME_UPPER COMP_DEP_NAME_LOWER)
		
		if(${COMP_DEP_NAME_UPPER}_BOOST)
			add_component_dependency_extern("${COMP_NAME}" "${BOOST_INCLUDEDIR}" "${Boost_${COMP_DEP_NAME_UPPER}_LIBRARY_DEBUG}" "${Boost_${COMP_DEP_NAME_UPPER}_LIBRARY_RELEASE}")
		endif()
		
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
				target_link_libraries(${COMP_NAME}_Lib PUBLIC ${COMP_DEP_NAME}_Lib)
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

function(add_component_test COMP_NAME COMP_FILES)
	message(STATUS "Building ${COMP_NAME}_Test as test executable for ${COMP_NAME}.")
	
	add_executable(${COMP_NAME}_Test ${COMP_FILES})
	set_target_properties(${COMP_NAME}_Test PROPERTIES FOLDER ${COMP_NAME})
	target_include_directories(${COMP_NAME}_Test PRIVATE "${BOOST_INCLUDEDIR}")
	target_link_libraries(${COMP_NAME}_Test PRIVATE optimized ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY_RELEASE})
	target_link_libraries(${COMP_NAME}_Test PRIVATE debug ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY_DEBUG})
	target_link_libraries(${COMP_NAME}_Test PRIVATE ${COMP_NAME}_Lib)

	enable_testing()
	add_test(${COMP_NAME}_Test ${COMP_NAME}_Test "--log_level=message")
	add_custom_command(TARGET ${COMP_NAME}_Test
		POST_BUILD
		COMMAND ${COMP_NAME}_Test ARGS "--log_level=message"
		COMMENT "Running ${COMP_NAME}_Test" VERBATIM)
endfunction()

function(add_component_dependency_extern COMP_NAME DEP_INCLUDE DEP_LIBRARY_DEBUG DEP_LIBRARY_RELEASE)
	component_verify(COMP_NAME COMP_NAME_UPPER COMP_NAME_LOWER)

	if(DEP_INCLUDE)
		if(${COMP_NAME_UPPER}_BUILD_EXE)
			message(STATUS ${DEP_INCLUDE})
			target_include_directories(${COMP_NAME} PRIVATE ${DEP_INCLUDE})
		endif()
		if(${COMP_NAME_UPPER}_BUILD_STATIC)
			target_include_directories(${COMP_NAME}_Lib PRIVATE ${DEP_INCLUDE})
		endif()
		if(${COMP_NAME_UPPER}_BUILD_SHARED)
			target_include_directories(${COMP_NAME}_Shared PRIVATE ${DEP_INCLUDE})
		endif()
	endif()
	
	if(DEP_LIBRARY_DEBUG AND DEP_LIBRARY_RELEASE)
		if(${COMP_NAME_UPPER}_BUILD_EXE)
			message(STATUS "Closed linking added for ${COMP_NAME}: ${DEP_LIBRARY_DEBUG} / ${DEP_LIBRARY_RELEASE}")
			target_link_libraries(${COMP_NAME} PRIVATE DEBUG ${DEP_LIBRARY_DEBUG})
			target_link_libraries(${COMP_NAME} PRIVATE OPTIMIZED ${DEP_LIBRARY_RELEASE})
		endif()
		if(${COMP_NAME_UPPER}_BUILD_STATIC)
			message(STATUS "Closed linking added for ${COMP_NAME}_Lib: ${DEP_LIBRARY_DEBUG} / ${DEP_LIBRARY_RELEASE}")
			target_link_libraries(${COMP_NAME}_Lib PRIVATE DEBUG ${DEP_LIBRARY_DEBUG})
			target_link_libraries(${COMP_NAME}_Lib PRIVATE OPTIMIZED ${DEP_LIBRARY_RELEASE})
		endif()
		if(${COMP_NAME_UPPER}_BUILD_SHARED)
			message(STATUS "Closed linking added for ${COMP_NAME}_Shared: ${DEP_LIBRARY_DEBUG} / ${DEP_LIBRARY_RELEASE}")
			target_link_libraries(${COMP_NAME}_Shared PRIVATE DEBUG ${DEP_LIBRARY_DEBUG})
			target_link_libraries(${COMP_NAME}_Shared PRIVATE OPTIMIZED ${DEP_LIBRARY_RELEASE})
		endif()
	endif()
endfunction()
