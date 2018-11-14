cmake_minimum_required(VERSION 3.12)
project(OpenGL_triangle)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)

link_libraries(OpenGL_common)
link_libraries(../external/glew-2.1.0/lib/Release/Win32/glew32s.lib)
link_libraries(../external/glfw-3.2.1.bin.WIN32/lib-vc2015/glfw3.lib)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(OpenGL_triangle main.cpp glad.c)

include_directories(../external/glew-2.1.0/include)
include_directories(../external/glfw-3.2.1.bin.WIN32/include)
include_directories(../external/glad/include)
include_directories(../external/glm/glm)
link_directories(../common)