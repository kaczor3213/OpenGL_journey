#include "../include/input_handling.hpp"

void input_handling::pointWindow(const GLFWwindow &window) {

}

void input_handling::initInput() {

}

void input_handling::procMouseZoomCam(const float &yoffs) {
	/*
	if (camZoom >= 1.0f && camZoom <= 45.0f) camZoom -= yoffs;
	if (camZoom <= 1.0f) camZoom = 1.0f;
	if (camZoom >= 45.0f) camZoom = 45.0f;
	*/
}

void input_handling::procKeysCam(camera &Cam, camMov dir, const float &inTime) {
	/*
	if (dir == FORWARD) Cam.camPos += Cam.frontPos * 2.5f * inTime;
	if (dir == BACKWARD) Cam.camPos -= Cam.frontPos * 2.5f * inTime;
	if (dir == RIGHT) Cam.camPos += Cam.right * 2.5f * inTime;
	if (dir == LEFT) Cam.camPos -= Cam.right * 2.5f * inTime;
	*/
}

void input_handling::procMouseRotCam(camera &Cam, const float &xoffs, const float &yoffs, bool constrain) {
	/*
	Cam.camYaw += xoffs * 0.1f;
	Cam.camPitch = yoffs * 0.1f;
	if (constrain)
	{
		if (Cam.camPitch > 89.0f) Cam.camPitch = 89.0f;
		if (Cam.camPitch < -89.0f) Cam.camPitch = -89.0f;
	}
	Cam.updateCam();
	*/
}
