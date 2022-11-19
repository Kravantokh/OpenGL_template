cmake_minimum_required(VERSION 3.22.2)

project(OpenGL_Template VERSION 1.0)

#Setting some variables
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

#Stop GLFW from generating docs, tests and examples
set( GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

set(GLFW_DIR ${CMAKE_SOURCE_DIR}/lib/glfw)
set(BU_GLW_DIR ${CMAKE_SOURCE_DIR}/lib/bu_glw)

#Adding sources to be built
add_subdirectory(${GLFW_DIR})
add_subdirectory(${BU_GLW_DIR})

include_directories(${GLFW_DIR}/include)

# Should examples be built?
if(DEFINED BUILD_EXAMPLES)
	add_subdirectory(${CMAKE_SOURCE_DIR}/examples)
endif()


# Add your files here




