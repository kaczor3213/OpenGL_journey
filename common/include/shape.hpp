#ifndef SHAPE_HPP
#define SHAPE_HPP

//make indices array generator

#include "vertices.hpp"

class shape
{
protected:
	//std::vector<unsigned> indices;
public:
	std::vector<unsigned> indices;
	vertices<point> coordinates;
	shape() {}
	std::vector<unsigned> indices_handle() { return indices; }
	virtual ~shape() {}
};


#endif 