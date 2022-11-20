# OpenGL_template

DISCLAIMER:
This project is work in progress and thus breaking changes may appear without any previou announcement.

Basic OpenGL project template for c++ with CMake, glfw and gl3w meant to work out of the box on Windows (currently considered untested due to recent major changes) and Linux and eliminate as much frustration as possible in the setup phase of any OpenGL project or OpenGL prototype. It includes glfw.

It also features my OpenGL C-style C++11 wrapper library for a less verbose API for OpenGL along with gl3w as the OpenGL function loader. [More details](https://github.com/Kravantokh/bu_glw).

You can find examples of how to use this API in the `examples` folder.

## Cloning
You should clone the repository with
`git clone --recursive https://github.com/Kravantokh/OpenGL_GLEW_GLFW_template/`\

## Current code

The file `src/main.cpp` contains a basic example code which creates an openGL context and opens it in a window with the help of glfw.

## Prerequisites (for using the included `compile.sh`)
* CMake
* GNU GCC (mingw on Windows)
* ninja
* glu\*
* Python (3 or 2 should both work)


\*Linux-only dependency - may be installed with the package manager. On Arch the package `glu` exists on its own. On Debian the package containing it is `libglu1-mesa-dev`. On other distros it may be contained in a different package.

## Build process
* Linux: run `build.sh`

On linux don't forget to run `chmod +x build.sh`.

Until now the build process has been succesfully tested on Arch Linux, Kubuntu 20.10 and Windows 10(before the major changes) with the mentioned build tools.

## Errors you may meet

`XInput headers not found; install libxi development package` - Installing the package `xorg-dev` may help on Debian distros.

