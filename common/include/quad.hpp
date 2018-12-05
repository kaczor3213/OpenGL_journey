#ifndef QUAD_HPP
#define QUAD_HPP

#include "vertices.hpp"
#include "shape.hpp"

class quad : public shape
{
public:
	quad();
	quad(const quad &other);
	quad(quad &&other) noexcept;
	quad& operator=(const quad &other);
	quad& operator=(quad &&other) noexcept;
	~quad() {}
	void render();
	void update();
};

#endif // !QUAD_CPP
