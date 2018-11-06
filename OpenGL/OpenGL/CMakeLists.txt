# CMakeList.txt : CMake project for OpenGL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable(OpenGL
	OpenGL.cpp
	OpenGL.hpp
	../common/shader.hpp
	../common/point.hpp
	../common/color.hpp
	../common/vertex.hpp
	../common/vertices.hpp
)

# TODO: Add tests and install targets if needed.
target_link_libraries(OpenGL
${ALL_LIBS}
)
