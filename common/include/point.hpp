#ifndef POINT_HPP
#define POINT_HPP

#include "vector2d.hpp"
#include "vector3d.hpp"
#include "color.hpp"

class Point : public Vector2d, public Vector3d
{
private:
	Color color;
public:
	Point();
	Point(const std::vector<float> &coordinate_vector, const Color &COLOR, const std::vector<float> &texture_vector);
	Point(const Vector3d &coordinate_vector, const Color &COLOR, const Vector2d &texture_vector);
	Point(const std::vector<float> &dataSet);
	Point(const Point &other);
	Point& operator=(const Point &other);
	Point(Point &&other) noexcept;
	Point& operator=(Point &&other) noexcept;
	virtual void set_coordinates(const float &X, const float &Y, const float &Z);
	virtual void set_color(const Color &COLOR);
	Color get_color();
};

#endif
