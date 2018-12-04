#ifndef POINT_HPP
#define POINT_HPP

#include "vector3d.hpp"
#include "color.hpp"

class point
{
private:
	bool check_in_range(const float &value);
	color _color;
public:
	vector3d position;
	point();
	point(const std::vector<float> &coordinate_vector, const color &COLOR);
	point(const vector3d &coordinate_vector, const color &COLOR);
	point(const point &other);
	point& operator=(const point &other);
	point(point &&other) noexcept;
	point& operator=(point &&other) noexcept;
	void set_color(const color &COLOR);
	color get_color();
};

#endif // !POINT_HPP
