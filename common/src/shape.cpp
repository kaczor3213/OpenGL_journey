#include "../include/shape.hpp"

shape::shape(const unsigned &vertices_count)
{
	
	indices.resize((vertices_count - 2)*3);
	int i = 0;
	unsigned int tmp_1{1}, tmp_2{2};
	while(i < indices.size())
	{
		indices[i] = 0;
		i++;
		indices[i] = tmp_1;
		i++;
		indices[i] = tmp_2;
		i++;
		tmp_1++;
		tmp_2++;
	}
	coordinates.resize(vertices_count);
}