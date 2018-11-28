//
// Created by Moew34 on 11/18/2018.
//
#include "../include/buffer.hpp"
#include <iostream>

buffer::~buffer()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void buffer::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void buffer::render(shape &set)
{
	VBO_DATA.resize(7 * set.coordinates.size());
	int k=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			VBO_DATA[k] = set.coordinates[i].position[j];
			k++;
		}
		for (int j = 0; j < 4; j++)
		{
			VBO_DATA[k] = set.coordinates[i].get_color().pigments[j];
			k++;
		}
    }
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, VBO_DATA.size() * sizeof(float), &VBO_DATA[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, set.indices.size() * sizeof(unsigned), &set.indices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}
