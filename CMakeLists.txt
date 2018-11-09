cmake_minimum_required(VERSION 3.12)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

project(OpenGL_journey)

add_subdirectory(common)
add_subdirectory(external/glfw-master)
add_subdirectory(external/glew-2.1.0)
add_subdirectory(external/glm)
add_subdirectory(OpenGL_triangle)
