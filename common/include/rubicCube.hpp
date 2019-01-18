#include <map>
#include <vector>
#include "cube.hpp"
#include "quad.hpp"
#include "input.hpp"

const Color COLOR_YELLOW(255, 255, 0, 255);
const Color COLOR_BLACK(0, 0, 0, 255);
const Color COLOR_RED(255, 0, 0, 255);
const Color COLOR_GREEN(0, 255, 0, 255);
const Color COLOR_BLUE(0, 0, 255, 255);

enum Way {
	CLOCKWISE,
	ANTI_CLOCKWISE
};
enum Face {
	UP,
	DOWN,
	RIGHTS,
	LEFTS,
	FRONT,
	BACK
};

class Side
{
public:
	Quad cover;
	std::vector<unsigned> cubesIndices;
};

class RubicCube
{
private:
	std::vector<Cube> cubes;
	std::map<Face,Side> relationGraph;
	void set_inner_covers();
	void set_cubes();
	void set_sides();
	void set_colors();
	void set_relations();

public:
	RubicCube();
	void rotate_face(Face,Way);
	void rotate_RubicCube();
	void animate();
};