#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
<<<<<<< HEAD

#include "vertices.hpp"
#include "shape.hpp"
#include "shader.hpp"

=======

#include "shape.hpp"

>>>>>>> dev
class triangle : public shape
{
public:
	triangle();
    triangle(const triangle &other);
    triangle(triangle &&other) noexcept;
    triangle& operator=(const triangle &other);
    triangle& operator=(triangle &&other) noexcept;
	~triangle() {}
<<<<<<< HEAD
=======
	virtual void render();
	virtual void draw();
>>>>>>> dev
};

#endif //TRIANGLE_HPP
