//
// Created by Moew34 on 11/18/2018.
//
#include "../include/buffer.hpp"
#include <iostream>

buffer::~buffer()
{
	glDeleteVertexArrays(1, *&VAO);
	glDeleteBuffers(1, *&VBO);
	glDeleteBuffers(1, *&EBO);
}

void buffer::add(shape &figure)
{
	set.push_back(figure);
}

void buffer::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(*VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void buffer::render()
{

	glGenVertexArrays(set.size(), *&VAO);
	glGenBuffers(set.size(), *&VBO);
	glGenBuffers(set.size(), *&EBO);

	for (auto &figure : set)
	{
		//parser
		VBO_DATA.resize(7 * figure.coordinates.size());
		int k = 0;
		for (int i = 0; i < figure.coordinates.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				VBO_DATA[k] = figure.coordinates[i].position[j];
				k++;
			}
			for (int j = 0; j < 4; j++)
			{
				VBO_DATA[k] = figure.coordinates[i].get_color().pigments[j];
				k++;
			}
		}
		//
		//indices generator
		bool not_done{ true };
		int i = 0, count = 0;
		std::vector<int> angle;
		std::vector<unsigned> tmp;
		for (int i = 0; i < figure.coordinates.size(); i++)
			tmp.push_back(i);
		while (not_done)
		{
			while (angle.size() < 3)
			{
				if (tmp[i] >= 0)
					angle.push_back(i);
				else
					i++;
				if (i >= tmp.size()) i = 0;
			}
			if (figure.coordinates[angle[0]].position[0] - figure.coordinates[angle[1]].position[0]) *
				(figure.coordinates[angle[2]].position[1] - figure.coordinates[angle[1]].position[1]) -
				(figure.coordinates[angle[2]].position[0] - figure.coordinates[angle[1]].position[0]) *
				(figure.coordinates[angle[0]].position[1] - figure.coordinates[angle[1]].position[1]) > 0
				)
			{
				for (auto vertice : angle)
					set.indices.push_back(vertice);
				tmp[angle[1]] = -1;
				count++;
				i = angle[2];
				angle.clear;
			}
			if (count == tmp.size()) not_done = false;
		}
		//
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, VBO_DATA.size() * sizeof(float), &VBO_DATA[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, figure.indices.size() * sizeof(unsigned int), &figure.indices[0], GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}
}
