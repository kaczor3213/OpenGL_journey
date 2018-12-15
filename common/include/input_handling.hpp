#ifndef INPUT_HANDLING_HPP
#define INPUT_HANDLING_HPP

#include <glad.h>
#include <glfw3.h>
#include "camera.hpp"

class input_handling
{
private:
	GLFWwindow &_window;
public:
	virtual void pointWindow(const GLFWwindow &window);
	virtual void initInput();
	virtual void procMouseZoomCam(const float &yoffs);
	virtual void procKeysCam(camera &Cam, camMov dir, const float &inTime);
	virtual void procMouseRotCam(camera &Cam, const float &xoffs, const float &yoffs, bool constrain);
};

#endif
