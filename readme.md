# OpenGL_GLEW_GLFW_template #

Basic OpenGL project template for c++ with CMake, glfw and gl3w meant to work out of the box on Windows and Linux and eliminate as much frustration as possible in the setup phase of any OpenGL project.

## Current code ##

The file `src/main.cpp` contains a basic example code which creates an openGL context and opens it in a window with the help of glfw.

## Prerequisites ##
* CMake (obviously)
* GNU GCC: g++ (mingw on windows)
* ninja
* glu\*


\*Linux-only dependency - may be installed with the package manager, in may case the command was `sudo pacman -S glu`

## Build process ##
* Windows: run build.bat
* Linux: run build.sh

Until now the build process has been tested on Windows 10 with the mentioned prerequisites.
