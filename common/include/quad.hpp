#ifndef QUAD_HPP
#define QUAD_HPP

#include "shape.hpp"

class Quad : public Shape
{
public:
	Quad();
	Quad(const Quad &other);
	Quad(Quad &&other) noexcept;
	Quad& operator=(const Quad &other);
	Quad& operator=(Quad &&other) noexcept;
	~Quad() {}
	virtual void render();
};

#endif
