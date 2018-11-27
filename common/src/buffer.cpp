//
// Created by Moew34 on 11/18/2018.
//
#include "../include/buffer.hpp"
#include <iostream>

///buffer needs several upgrades
buffer::~buffer()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void buffer::set_buffers()
{
	//int tmp_size = VBO_DATA.size();
	//float tmp_arr[tmp_size];
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(VBO_DATA), VBO_DATA, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void buffer::bind_and_draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void buffer::parse_to_glsl(shape &set)
{
	VBO_DATA.resize(7*set.coordinates.size());
	int k=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			VBO_DATA[k] = set.coordinates[i].position[j];
			k++;
		}
		for (int j = 0; j < 3; j++)
		{
			VBO_DATA[k] = set.coordinates[i].get_color().pigments[j];
			k++;
		}
    }
}
