cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

set(OpenGL_USE_STATIC_LIBS ON)

set(SRC
        include/shader.hpp
        include/point.hpp
        include/color.hpp
        include/vertex.hpp
        include/vertices.hpp
        include/opengl.hpp
        src/color.cpp
        src/point.cpp
        src/shader.cpp
        src/vertex.cpp
        )

set(OpenGL_INCLUDE_DIR
        ../external/glad/include/
        ../external/glfw-3.1.2/include/
        ../external/glew-2.1.0/include/
        ../external/glm/
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw3
        glew32
        )

find_package(OpenGL REQUIRED)

project(OpenGLCommon VERSION 1.0)

include_directories(include ${OpenGL_INCLUDE_DIR})

add_library(${PROJECT_NAME} SHARED ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})


