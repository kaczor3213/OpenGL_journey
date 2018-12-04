#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "vertices.hpp"

class shape
{
public:
	std::vector<unsigned int> indices;
	vertices<point> coordinates;
	shape() {}
	shape(const unsigned &vertices_count);
	virtual ~shape() {}
};


#endif 