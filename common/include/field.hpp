#ifndef FIELD_HPP
#define FIELD_HPP

#include "shape.hpp"

class Field : public Shape
{
private:
	float cross_product(const int &f_v, const int &s_v, const int &r_p);
public:
	explicit Field(const unsigned &size);
	Field(const Field &other);
	Field(Field &&other) noexcept;
	Field& operator=(const Field &other);
	Field& operator=(Field &&other) noexcept;
	~Field() {}
	void resize(const unsigned &size);
	virtual void render();
	virtual void update();
};

#endif