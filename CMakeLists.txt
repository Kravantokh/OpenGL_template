cmake_minimum_required(VERSION 3.22.2)

project(OpenGL_Test VERSION 1.0)

#Make a warning disappear
cmake_policy(SET CMP0072 NEW)

#Setting some variables
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/lib/glfw/)
set(GL3W_DIR ${PROJECT_SOURCE_DIR}/lib/gl3w/)

#Stop GLFW from generating docs, tests and examples
set( GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

#Looking for some dependencies
find_package(Python COMPONENTS Interpreter)
find_package( OpenGL REQUIRED )

#Handling Python and gl3w download
if(NOT Python_Interpreter_FOUND)
	message(FATAL_ERROR "Python could not be found! The compilation can not proceed without a Python interpreter! (gl3w will be missing)")
endif()

if (WIN32)
	#Apparently on windows despite having python3 installed it would not recognize python3 as a command, so only python should be run.
	message("Successfully found Python. Running download script for gl3w.")
	execute_process(COMMAND python gl3w_gen.py --root ${PROJECT_BINARY_DIR}/lib/gl3w WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/gl3w)

#On linux the command does matter, thus it is tested which version to use.
elseif(${Python_VERSION} GREATER_EQUAL 3.0)
	message("Successfully found Python3. Running download script for gl3w.")
	execute_process(COMMAND python3 gl3w_gen.py --root ${PROJECT_BINARY_DIR}/lib/gl3w WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/gl3w)

elseif(${Python_VERSION} LESS 3.0)
	message("Successfully found Python2. Running download script for gl3w.")
	execute_process(COMMAND python gl3w_gen.py --root ${PROJECT_BINARY_DIR}/lib/gl3w WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/gl3w)
endif()

#Adding sources to be built
add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
add_subdirectory(${GL3W_DIR})
add_subdirectory(${GLFW_DIR})

include_directories(${GL3W_DIR}/include/ ${GLFW_DIR}/include/)

target_link_libraries(main glfw gl3w ${OPENGL_LIBRARIES})
