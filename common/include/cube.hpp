#ifndef CUBE_HPP
#define CUBE_HPP

#include "shape.hpp"

const color COLOR_YELLOW(255, 255, 0, 255);
const color COLOR_BLACK(0, 0, 0, 255);
const color COLOR_RED(255, 0, 0, 255);
const color COLOR_GREEN(0, 255, 0, 255);
const color COLOR_BLUE(0, 0, 255, 255);

class cube : public shape {
public:
	cube();
	~cube() {}
	void generate();
	void render_cube();
	void draw();
};

#endif
