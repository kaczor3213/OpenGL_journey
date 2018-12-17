#ifndef ANIMATE_HPP
#define ANIMATE_HPP

#include "../include/model_transform.hpp"
#include "../include/camera.hpp"

class animate : public model_transform, public camera
{
public:
	animate() {}
	~animate() {}
};
#endif
