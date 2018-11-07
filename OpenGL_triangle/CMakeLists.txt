cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIST
        ../common/include/shader.hpp
        ../common/include/point.hpp
        ../common/include/color.hpp
        ../common/include/vertex.hpp
        ../common/include/vertices.hpp
        ../common/src/color.cpp
        ../common/src/point.cpp
        ../common/src/shader.cpp
        ../common/src/vertex.cpp
        )

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw3
        glew32
        )

find_package(OpenGL REQUIRED)

project(OpenGL_triangle)

include_directories(
        ${PROJECT_SOURCE_DIR}/external/glad/include/
        ${PROJECT_SOURCE_DIR}/external/glfw-3.1.2/include/
        ${PROJECT_SOURCE_DIR}/external/glew-2.1.0/include/
        ${PROJECT_SOURCE_DIR}/external/glm/
        ${PROJECT_SOURCE_DIR}/common/include
)

add_executable(${PROJECT_NAME}  ${SOURCE_LIST})

target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})


