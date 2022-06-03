cmake_minimum_required(VERSION 3.10)

project(OpenGL_Test VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( OpenGL REQUIRED )

set( GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

set(GLFW_DIR ${PROJECT_SOURCE_DIR}/lib/glfw/)
set(GL3W_DIR ${PROJECT_SOURCE_DIR}/lib/gl3w/)

#Some blackmagic from an issue (https://github.com/skaslev/gl3w/issues/66) on the github page of gl3w.
execute_process(COMMAND python gl3w_gen.py --root ${PROJECT_BINARY_DIR}/lib/gl3w WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/gl3w)

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_subdirectory(${GL3W_DIR})
add_subdirectory(${GLFW_DIR})

include_directories(${GL3W_DIR}/include/ ${GLFW_DIR}/include/)

target_link_libraries(main glfw gl3w ${OPENGL_LIBRARIES})
