#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

class vertex {
	bool check_in_range(const float &value);
public:
	std::vector<float> coordinates;
	vertex();
	vertex(const double &x,const double &y,const double &z);
	vertex(const vertex &other);
	vertex& operator=(const vertex &other);
	vertex(vertex &&other) noexcept;
	vertex& operator=(vertex &&other) noexcept;
	virtual ~vertex() {}
};

#endif