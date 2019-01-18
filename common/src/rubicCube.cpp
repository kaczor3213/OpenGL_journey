#include "../include/rubicCube.hpp"

RubicCube::RubicCube()
{
	set_sides();
	set_colors();
	set_inner_covers();
	set_relations();
}

void RubicCube::set_cubes() {
	cubes.resize(26);
	for (auto &cube : cubes)
		cube.coordinates = Vertices<Point>(load_from_file("../../Resources/cube.txt"));
	//dorobic plik z pozycjami poszczegolnych szescianow
}

void RubicCube::set_sides() {
	for (auto &side : relationGraph)
		side.second.cubesIndices.resize(9);
}