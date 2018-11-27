#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "vertices.hpp"

class shape
{
protected:
	std::vector<double> indices;
public:
	vertices<point> coordinates;
	shape() {
	}
	virtual ~shape() {}
};


#endif 