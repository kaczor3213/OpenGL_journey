# CMakeList.txt : CMake project for OpenGL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable(OpenGL
	OpenGL.cpp
	OpenGL.hpp
	../common/headers/shader.hpp
	../common/headers/point.hpp
	../common/headers/color.hpp
	../common/headers/vertex.hpp
	../common/headers/vertices.hpp
	../common/src/shader.cpp
	../common/src/point.cpp
	../common/src/color.cpp
	../common/src/vertex.cpp
	../common/src/vertices.cpp
)

# TODO: Add tests and install targets if needed.
target_link_libraries(OpenGL
${ALL_LIBS}
)
