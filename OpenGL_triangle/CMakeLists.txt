cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

set(SRC
        main.cpp
        glad.c
        )

set(LIBS
        OpenGL_common
        ${OPENGL_gl_LIBRARY}
        ${GLFW_LIBRARIES}
        ${GLEW_LIBRARIES}
        )
find_package(OpenGL REQUIRED)

include_directories(
        ../common/include/
        ../external/glad/include/
        ../external/glfw-master/include/
        ../external/glew-2.1.0/include/
        ../external/glm/
)

link_directories(../common)

project(OpenGL_triangle VERSION 1.0)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${LIBS})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})



