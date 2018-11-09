cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

set(SRC
        include/shader.hpp
        include/point.hpp
        include/color.hpp
        include/vertex.hpp
        include/vertices.hpp
        include/opengl.hpp
        src/glad.c
        src/color.cpp
        src/point.cpp
        src/shader.cpp
        src/vertex.cpp
        )

set(LIBS
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

project(OpenGL_common VERSION 1.0)

add_library(${PROJECT_NAME} SHARED ${SRC})

target_link_libraries(${PROJECT_NAME} ${LIBS})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})


