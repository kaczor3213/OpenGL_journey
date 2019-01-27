#include "../include/field.hpp"

Field::Field(const unsigned &size) {
	coordinates.resize(size);
}

Field::Field(const Field &other) {
	EBO = other.EBO;
	VBO = other.VBO;
	VAO = other.VAO;
	VBO_DATA = other.VBO_DATA;
	indices = other.indices;
	coordinates = other.coordinates;
}

Field::Field(Field &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

Field& Field::operator=(const Field &other) {
	return *this = Field(other);
}

Field& Field::operator=(Field &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

void Field::resize(const unsigned &size) {
	coordinates.resize(size);
	update();
}

float Field::cross_product(const int &f_v, const int &s_v, const int &r_p)
{
	return  (coordinates[f_v].x - coordinates[r_p].x) *
		(coordinates[s_v].y - coordinates[r_p].y) -
		(coordinates[s_v].x - coordinates[r_p].x) *
		(coordinates[f_v].y - coordinates[r_p].y);
}

void Field::render()
{
	/*
	std::vector<float> t;
	t.push_back(cross_product(1, coordinates.size() - 1 , 0));
	for (int i = 1; i < coordinates.size() - 1; i++)
		t.push_back(cross_product(i+1,i-1,i));
	t.push_back(cross_product(0, coordinates.size() - 2, coordinates.size() - 1));
	*/

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
			((coordinates[angle[0]].x - coordinates[angle[0]].x) *
			(coordinates[angle[2]].y - coordinates[angle[2]].y) -
			(coordinates[angle[2]].x - coordinates[angle[0]].x) *
			(coordinates[angle[0]].y - coordinates[angle[2]].y)) < 0
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
	data_parser();
	buff_handle();
}

void Field::update()
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
			((coordinates[angle[0]].x - coordinates[angle[0]].x) *
			(coordinates[angle[2]].y - coordinates[angle[2]].y) -
			(coordinates[angle[2]].x - coordinates[angle[0]].x) *
			(coordinates[angle[0]].y - coordinates[angle[2]].y)) < 0
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

