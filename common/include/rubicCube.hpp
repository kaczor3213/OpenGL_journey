#include <map>
#include <vector>
#include "cube.hpp"
#include "quad.hpp"
#include "input.hpp"

const Color COLOR_WHITE(255, 255, 255, 255);
const Color COLOR_YELLOW(255, 255, 0, 255);
const Color COLOR_ORANGE(175, 99, 0, 255);
const Color COLOR_RED(255, 0, 0, 255);
const Color COLOR_GREEN(0, 255, 0, 255);
const Color COLOR_BLUE(0, 0, 255, 255);
const Color COLOR_BLACK(0, 0, 0, 255);

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
	std::vector<unsigned> cubesIndices;
};

class RubicCube : public Shape
{
private:
	
	std::map<Face,Side> relationGraph;
	
	void set_cubes();
	void set_inner_covers();
	void set_colors();
	

	void set_sides();
	Quad my_quad;
	//void set_relations();
	std::vector<Cube> cubes;
	std::vector<Quad> covers;
public:
	
	RubicCube();
	void render();
	void draw();
	void handle_input(GLFWwindow *&window);
	//void rotate_face(Face,Way);
	//void rotate_RubicCube();
	//void animate();
};