#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "vector3d.hpp"

class vertex {
	bool check_in_range(const double &value);
public:
    vector3d position;
    vertex() {}
	vertex(const std::vector<double> &coordinate_vector);
    vertex(const vector3d &coordinate_vector);
	vertex(const vertex &other);
	vertex& operator=(const vertex &other);
	vertex(vertex &&other) noexcept;
	vertex& operator=(vertex &&other) noexcept;
	virtual ~vertex() {}
};

#endif