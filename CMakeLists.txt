cmake_minimum_required(VERSION 3.10)

project(OpenGL_Test VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( OpenGL REQUIRED )

set( GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

set(GLFW_DIR ${PROJECT_SOURCE_DIR}/lib/glfw)
set(GLEW_DIR ${PROJECT_SOURCE_DIR}/lib/glew)

add_subdirectory(${GLEW_DIR}/build/cmake/)
add_subdirectory(${GLFW_DIR})

add_compile_definitions(GLEW_STATIC)

add_executable(main src/main.cpp)

include_directories(${GLEW_DIR}/include/ ${GLFW_DIR}/include/)

target_link_libraries(main glfw ${GLFW_LIBRARIES} ${PROJECT_SOURCE_DIR}/build/lib/libglew32.a ${OPENGL_LIBRARIES})
