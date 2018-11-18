cmake_minimum_required(VERSION 3.12)
project(OpenGL_common VERSION 1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)

set(SRC
        include/shader.hpp
        src/shader.cpp
        include/point.hpp
        src/point.cpp
        include/color.hpp
        src/color.cpp
        include/vertex.hpp
        src/vertex.cpp
        include/vertices.hpp
        include/triangle.hpp
        src/triangle.cpp
        src/glad.c
        include/vector3d.hpp
        src/vector3d.cpp
        src/buffer.cpp
        include/buffer.hpp)


find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED ${SRC})

link_libraries(../external/glew-2.1.0/lib/Release/Win32/glew32s.lib)
link_libraries(../external/glfw-3.2.1.bin.WIN32/lib-vc2015/glfw3.lib)

include_directories(include)
include_directories(../external/glew-2.1.0/include)
include_directories(../external/glfw-3.2.1.bin.WIN32/include)
include_directories(../external/glad/include)
include_directories(../external/glm/glm)

#target_link_libraries(${PROJECT_NAME} ../external/glfw-3.2.1.bin.WIN32/lib-vc2015/glfw3)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})





