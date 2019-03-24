cmake_minimum_required(VERSION 3.0)

project( "canopen" CXX)


################################################################################
## version file ##
##################

set(${PROJECT_NAME}_VERSION_SRC "${CMAKE_CURRENT_BINARY_DIR}/version.cc")
set(${PROJECT_NAME}_NAMESPACE ${PROJECT_NAME})

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/version.cc
	OUTPUT __version_${PROJECT_NAME}
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tools/version_writer.sh ${CMAKE_CURRENT_SOURCE_DIR} ${${PROJECT_NAME}_NAMESPACE} ${PROJECT_NAME} > ${CMAKE_CURRENT_BINARY_DIR}/version.cc
)

add_custom_target(${PROJECT_NAME}_version
	ALL
	DEPENDS __version_${PROJECT_NAME}
)

set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/version.cc PROPERTIES GENERATED TRUE)


################################################################################
##  library  ##
###############

add_library( ${PROJECT_NAME}
	${${PROJECT_NAME}_VERSION_SRC}
)

target_include_directories( ${PROJECT_NAME}
	PUBLIC src/
)


################################################################################
## unit tests ##
################

add_executable( ${PROJECT_NAME}-test EXCLUDE_FROM_ALL
	${SOURCES}
	tests/catch.cc
	tests/version.cc
	tests/sdo/to_string.cc
	tests/bit_field.cc
	tests/od.cc
)

target_link_libraries( ${PROJECT_NAME}-test
	PRIVATE ${PROJECT_NAME}
)
