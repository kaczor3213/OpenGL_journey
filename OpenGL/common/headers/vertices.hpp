#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "point.hpp"


float **parse_to_glsl(std::vector<point> &vertices)
{
	float **parser = new float*[vertices.size()+1];
	for (int i=0; i< vertices.size()+1; i++)
		parser[i] = new float[7];

	for (int i = 0; i < vertices.size() + 1; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j < 4)
				parser[i][j] = vertices[i].coordinates[j];
			else
				parser[i][j] = vertices[i].get_color().pigments[j-3];
		}
	}
	return parser;
}

#endif // !VERTICES_HPP
