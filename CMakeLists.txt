cmake_minimum_required(VERSION 3.22.2)

project(OpenGL_Template VERSION 1.0)

#Setting some variables
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Stop GLFW from generating docs, tests and examples
set( GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

set(GLFW_DIR ${CMAKE_SOURCE_DIR}/lib/glfw)
set(BU_GLW_DIR ${CMAKE_SOURCE_DIR}/lib/bu_glw)

#Adding sources to be built
add_subdirectory(${GLFW_DIR})
add_subdirectory(${BU_GLW_DIR})

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)


include_directories(
	${GLFW_DIR}/include
	)

target_link_libraries(main bu_glw glfw gl3w ${OPENGL_LIBRARIES})
