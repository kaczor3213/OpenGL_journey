#ifndef ANIMATE_HPP
#define ANIMATE_HPP

#include "../include/model_transform.hpp"
#include "../include/camera.hpp"

class Animate : public ModelTransform, public Camera
{
public:
	Animate() {}
	~Animate() {}
};
#endif
