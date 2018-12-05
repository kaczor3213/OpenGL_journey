#include "../include/polygon.hpp"

polygon::polygon(const unsigned &size) {
	indices.resize((size - 2) * 3);
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
	indices.resize((size - 2) * 3);
	coordinates.resize(size);
}

void polygon::render()
{
	//indices generator
	bool not_done{ true };
	int i = 0, count = 0;
	std::vector<unsigned int> angle;
	std::vector<unsigned> tmp;
	for (int i = 0; i < coordinates.size(); i++)
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
		if (
			((coordinates[angle[0]].position[0] - coordinates[angle[1]].position[0]) *
			(coordinates[angle[2]].position[1] - coordinates[angle[1]].position[1]) -
			(coordinates[angle[2]].position[0] - coordinates[angle[1]].position[0]) *
			(coordinates[angle[0]].position[1] - coordinates[angle[1]].position[1])) > 0
			)
		{
			for (auto vertice : angle)
				indices.push_back(vertice);
			tmp[angle[1]] = -1;
			count++;
			i = angle[2];
			angle.clear;
		}
		if (count == tmp.size()) not_done = false;
	}
}

void polygon::update()
{
	//indices generator
	bool not_done{ true };
	int i = 0, count = 0;
	std::vector<unsigned int> angle;
	std::vector<unsigned> tmp;
	for (int i = 0; i < coordinates.size(); i++)
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
		if (((coordinates[angle[0]].position[0] - coordinates[angle[1]].position[0]) *
			(coordinates[angle[2]].position[1] - coordinates[angle[1]].position[1]) -
			(coordinates[angle[2]].position[0] - coordinates[angle[1]].position[0]) *
			(coordinates[angle[0]].position[1] - coordinates[angle[1]].position[1])) > 0
			)
		{
			for (auto vertice : angle)
				indices.push_back(vertice);
			tmp[angle[1]] = -1;
			count++;
			i = angle[2];
			angle.clear;
		}
		if (count == tmp.size()) not_done = false;
	}
}

