#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "shape.hpp"

class polygon : public shape
{
private:
	float cross_product(const int &f_v, const int &s_v, const int &r_p);
public:
	explicit polygon(const unsigned &size);
	polygon(const polygon &other);
	polygon(polygon &&other) noexcept;
	polygon& operator=(const polygon &other);
	polygon& operator=(polygon &&other) noexcept;
	~polygon() {}
	void resize(const unsigned &size);
	virtual void render();
	virtual void update();
};

#endif //POLYGON_HPP