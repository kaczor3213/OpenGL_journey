#ifndef SHAPE_HPP
#define SHAPE_HPP

//make indices array generator

#include "vertices.hpp"

class shape
{
protected:
	//std::vector<unsigned> indices;
public:
	std::vector<unsigned int> indices;
	vertices<point> coordinates;
	shape() {}
	virtual ~shape() {}
};


#endif 