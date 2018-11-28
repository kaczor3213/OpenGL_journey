#ifndef QUAD_HPP
#define QUAD_HPP

///prepare for proper indices arrays
#include "vertices.hpp"
#include "shape.hpp"
#include "shader.hpp"

class quad : public shape
{
public:
	quad();
	quad(const quad &other);
	quad(quad &&other) noexcept;
	quad& operator=(const quad &other);
	quad& operator=(quad &&other) noexcept;
	~quad() {}
};

#endif // !QUAD_CPP
