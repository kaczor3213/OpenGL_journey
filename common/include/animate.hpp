#ifndef ANIMATE_HPP
#define ANIMATE_HPP

#include "../include/model_transform.hpp"
#include "../include/camera.hpp"
#include "../include/worldspace.hpp"

class animate : public model_transform, public camera, public worldspace
{
public:
	animate() {}
	~animate() {}
};
#endif // !ANIMATE_HPP
