#include "../include/color.hpp"

color::color(const unsigned &RED,
	const unsigned &GREEN,
	const unsigned &BLUE,
	const unsigned &ALPHA)
{
	if (check_range(RED) && check_range(GREEN) && check_range(BLUE) && check_range(ALPHA))
	{
		double tmp = 1.0f / 255.0f;
		pigments.push_back(tmp * RED);
		pigments.push_back(tmp * GREEN);
		pigments.push_back(tmp * BLUE);
		pigments.push_back(tmp * ALPHA);
		generate_buffer();
	}
	else
	{
		exit(-1);
	}
}

color::color(const color& other)
{
	pigments = other.pigments;
	buffer.clear();
	generate_buffer();
}

color& color::operator=(const color &other)
{
	return *this = color(other);
}

color::color(color &&other) noexcept
{
	pigments = other.pigments;
	buffer.clear();
	generate_buffer();
	other.pigments.clear();
}

color& color::operator=(color &&other) noexcept
{
	buffer.clear();
	std::swap(pigments, other.pigments);
	generate_buffer();
	other.pigments.clear();
	return *this;
}

color::~color()
{
	pigments.clear();
	buffer.clear();
}

bool color::check_range(const unsigned &VALUE)
{
	if (0 <= VALUE <= 255) return true;
	else return false;
}

void color::generate_buffer()
{
	buffer << pigments[0] << "f, "
		<< pigments[1] << "f, "
		<< pigments[2] << "f, "
		<< pigments[3] << "f ";
}

std::string color::get_buffer()
{
	return buffer.str();
}

void color::set_color(const unsigned &RED,
	const unsigned &GREEN,
	const unsigned &BLUE,
	const unsigned &ALPHA)
{
	pigments.clear();
	buffer.clear();
	if (check_range(RED) && check_range(GREEN) && check_range(BLUE) && check_range(ALPHA))
	{
		double tmp = 1.0 / 255.0;
		pigments.push_back(tmp * RED);
		pigments.push_back(tmp * GREEN);
		pigments.push_back(tmp * BLUE);
		pigments.push_back(tmp * ALPHA);
		generate_buffer();
	}
	else
	{
		exit(-1);
	}
}