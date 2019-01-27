#include "../include/color.hpp"

Color::Color(const unsigned &RED,
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

Color::Color(const std::vector<float> &pigmentsSet)
{
	pigments = pigmentsSet;
	buffer.clear();
}

Color::Color(const Color& other)
{
	pigments = other.pigments;
	buffer.clear();
}

Color& Color::operator=(const Color &other)
{
	return *this = Color(other);
}

Color::Color(Color &&other) noexcept
{
	pigments = other.pigments;
	buffer.clear();
	other.pigments.clear();
}

Color& Color::operator=(Color &&other) noexcept
{
	buffer.clear();
	std::swap(pigments, other.pigments);
	other.pigments.clear();
	return *this;
}

Color::~Color()
{
	pigments.clear();
	buffer.clear();
}

bool Color::check_range(const unsigned &VALUE)
{
	if (0 <= VALUE && VALUE <= 255) return true;
	else return false;
}

void Color::set_color(const unsigned &RED,
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