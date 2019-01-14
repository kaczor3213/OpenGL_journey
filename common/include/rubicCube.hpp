#include <map>
#include <vector>
#include "cube.hpp"
#include "quad.hpp"

enum Way {
	CLOCKWISE,
	ANTI_CLOCKWISE
};
enum Face {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	FRONT,
	BACK
};

class Side
{
public:
	Quad cover;
	std::map<unsigned,Cube> wall;
};

class RubicCube
{
private:
	std::map<Face,Side> relationGraph;
	void set_inner_cover();
	void set_cubes();
	void set_colors();
	void set_relations();

public:
	RubicCube();
	void rotate_face(Face,Way);
	void rotate_RubicCube();
	void animate();
};