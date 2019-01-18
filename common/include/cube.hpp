#ifndef CUBE_HPP
#define CUBE_HPP

#include "shape.hpp"

class Cube : public Shape {
public:
	Cube();
	~Cube() {}
	void generate();
	void render_cube();
	void draw();
};

#endif
