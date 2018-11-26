#ifndef POINT_HPP
#define POINT_HPP

#include "vertex.hpp"
#include "color.hpp"

class point : public vertex
{
private:
	color _color;
public:
	point();
	point(const vertex &VERTEX, const color &COLOR);
	point(const std::vector<double> &coordinate_vector, const color &COLOR);
	point(const vector3d &coordinate_vector, const color &COLOR);
	point(const point &other);
	point& operator=(const point &other);
	point(point &&other) noexcept;
	point& operator=(point &&other) noexcept;
	void set_color(const color &COLOR);
	color get_color();
};

#endif // !POINT_HPP
