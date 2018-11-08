cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

set(SRC main.cpp glad.c)
set(COMMON_LIB "OpenGLCommon")

include_directories(
        ../common/include
)
link_directories(../common)

project(OpenGL_triangle VERSION 1.0)
add_executable(${PROJECT_NAME}  ${SRC})
target_link_libraries(${PROJECT_NAME} ${COMMON_LIB})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})



