#ifndef ANIMATE_HPP
#define ANIMATE_HPP

#include "../include/model_transform.hpp"
#include "../include/camera.hpp"
#include "../include/worldspace.hpp"

class animate : public worldspace, public model_transform, public camera
{
public:
	animate() {}
	~animate() {}
};
#endif
