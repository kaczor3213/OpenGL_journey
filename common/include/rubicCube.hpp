#include <map>
#include <vector>
#include <set>
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
	ANTICLOCKWISE,
	NOWAY
};

enum Face {
	UP,
	DOWN,
	RIGHTS,
	LEFTS,
	FRONT,
	BACK,
	NOFACE
};

class Side
{
public:
	std::set<unsigned> cubesIndices;
};

class RubicCube : public Shape
{
private:
	std::map<Face, Side> relationGraph;
	std::vector<Cube> cubes;
	std::vector<Quad> covers;
	
	void set_cubes();
	void set_inner_covers();
	void set_colors();
	void set_relations();
	void twick_rotation();
	void animate_side(std::pair<Face, Way> move);
	void process_rubic_keyboard(std::pair<Face, Way> move, const float &deltaTime);
	std::pair<Face,Way>rubic_keyboard_callback(GLFWwindow *window);
	
public:
	RubicCube();
	void render();
	void draw();
	void handle_input(GLFWwindow *&window);
	//void rotate_RubicCube();
};