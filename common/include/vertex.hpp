#ifndef VERTEX_HPP
#define VERTEX_HPP

class vertex {
	bool check_in_range(const double &value);
public:
    double position;
	vertex();
	vertex(const double &POSITION);
	vertex(const vertex &other);
	vertex& operator=(const vertex &other);
	vertex(vertex &&other) noexcept;
	vertex& operator=(vertex &&other) noexcept;
	virtual ~vertex() {}
};

#endif