#ifndef CUBE_HPP
#define CUBE_HPP

#include "shape.hpp"

const Color COLOR_YELLOW(255, 255, 0, 255);
const Color COLOR_BLACK(0, 0, 0, 255);
const Color COLOR_RED(255, 0, 0, 255);
const Color COLOR_GREEN(0, 255, 0, 255);
const Color COLOR_BLUE(0, 0, 255, 255);

class Cube : public Shape {
public:
	Cube();
	~Cube() {}
	void generate();
	void render_cube();
	void draw();
};

#endif
