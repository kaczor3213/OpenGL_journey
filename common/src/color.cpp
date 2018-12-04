#include "../include/color.hpp"

color::color(const unsigned &RED,
	const unsigned &GREEN,
	const unsigned &BLUE,
	const unsigned &ALPHA)
{
	if (check_range(RED) && check_range(GREEN) && check_range(BLUE) && check_range(ALPHA))
	{
		float tmp = 1.0f / 255.0f;
		pigments.push_back(tmp * RED);
		pigments.push_back(tmp * GREEN);
		pigments.push_back(tmp * BLUE);
		pigments.push_back(tmp * ALPHA);
	}
	else
		exit(-1);
}

color::color(const color& other)
{
	pigments = other.pigments;
	buffer.clear();
}

color& color::operator=(const color &other)
{
	return *this = color(other);
}

color::color(color &&other) noexcept
{
	pigments = other.pigments;
	buffer.clear();
	other.pigments.clear();
}

color& color::operator=(color &&other) noexcept
{
	buffer.clear();
	std::swap(pigments, other.pigments);
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
	if (0 <= VALUE && VALUE <= 255) return true;
	else return false;
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
		float tmp = 1.0f / 255.0f;
		pigments.push_back(tmp * RED);
		pigments.push_back(tmp * GREEN);
		pigments.push_back(tmp * BLUE);
		pigments.push_back(tmp * ALPHA);
	}
	else
		exit(-1);
}