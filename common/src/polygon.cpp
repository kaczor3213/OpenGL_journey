#include "../include/polygon.hpp"
#include <iostream>
#include <chrono>
polygon::polygon(const unsigned &size) {
	coordinates.resize(size);
}

polygon::polygon(const polygon &other) {
	EBO = other.EBO;
	VBO = other.VBO;
	VAO = other.VAO;
	VBO_DATA = other.VBO_DATA;
	indices = other.indices;
	coordinates = other.coordinates;
}

polygon::polygon(polygon &&other) noexcept {

	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

polygon& polygon::operator=(const polygon &other) {
	return *this = polygon(other);
}

polygon& polygon::operator=(polygon &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

void polygon::resize(const unsigned &size) {
	coordinates.resize(size);
	update();
}

void polygon::render()
{
	auto start = std::chrono::steady_clock::now();	
	bool not_done{ true };
	int i = 0, count = 0;
	std::vector<unsigned int> angle;
	std::vector<int> tmp;
	for (int i = 0; i < coordinates.size(); i++)
		tmp.push_back(i);
	while (not_done)
	{
		while (angle.size() < 3)
		{
			if (tmp[i] >= 0)
			{
				angle.push_back(tmp[i]); 
				i++;
			}	
			else
				i++;
			if (i >= tmp.size()) i = 0;
		}
		if (
			((coordinates[angle[0]].position[0] - coordinates[angle[1]].position[0]) *
			(coordinates[angle[2]].position[1] - coordinates[angle[1]].position[1]) -
			(coordinates[angle[2]].position[0] - coordinates[angle[1]].position[0]) *
			(coordinates[angle[0]].position[1] - coordinates[angle[1]].position[1])) < 0
			)
		{
			for (auto x : angle)
				indices.push_back(x);
			tmp[angle[1]] = -1;
			i=angle[2];
			count++;
			angle.clear();
		}
		else
		{
			i = angle[1];
			angle.clear();
		}
		if (count == tmp.size()-2) not_done = false;
	}
	auto finish = std::chrono::steady_clock::now();
	double elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();
	std::cout << elapsed_seconds;
	data_parser();
	buff_handle();

}

void polygon::update()
{
	bool not_done{ true };
	int i = 0, count = 0;
	std::vector<unsigned int> angle;
	std::vector<int> tmp;
	for (int i = 0; i < coordinates.size(); i++)
		tmp.push_back(i);

	while (not_done)
	{
		while (angle.size() < 3)
		{
			if (tmp[i] >= 0)
			{
				angle.push_back(tmp[i]);
				i++;
			}
			else
				i++;
			if (i >= tmp.size()) i = 0;

		}
		if (
			((coordinates[angle[0]].position[0] - coordinates[angle[1]].position[0]) *
			(coordinates[angle[2]].position[1] - coordinates[angle[1]].position[1]) -
			(coordinates[angle[2]].position[0] - coordinates[angle[1]].position[0]) *
			(coordinates[angle[0]].position[1] - coordinates[angle[1]].position[1])) < 0
			)
		{
			for (auto x : angle)
				indices.push_back(x);
			tmp[angle[1]] = -1;
			i = angle[2];
			count++;
			angle.clear();
		}
		else
		{
			i = angle[1];
			angle.clear();
		}

		if (count == tmp.size() - 2) not_done = false;
	}
	data_parser();
	buff_handle();
}
