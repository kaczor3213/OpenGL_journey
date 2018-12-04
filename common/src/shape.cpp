#include "../include/shape.hpp"

shape::shape(const unsigned &vertices_count)
{
	indices.resize((vertices_count - 2)*3);
	
	coordinates.resize(vertices_count);
}