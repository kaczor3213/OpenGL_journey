#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "input_handling.hpp"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <string>


enum camMov { FORWARD, BACKWARD, LEFT, RIGHT };

class camera
{
private:
	friend class input_handling;
	glm::vec3 camPos;
	glm::vec3 frontPos;
	glm::vec3 upPos;
	glm::vec3 worldUpPos;
	glm::vec3 right;
	float camYaw;
	float camPitch;
	float camZoom;
protected:
	unsigned viewLoc;
	glm::mat4 view;
public:
	camera();
	camera(const camera &other);
	camera(camera &&other) noexcept;
	camera& operator=(const camera &other);
	camera& operator=(camera &&other) noexcept;
	~camera() {}
	virtual void moveCam(const float &horizontal, const float &vertical, const float &depth);
	virtual void rotateCam(const float &speed_scale, const float &horizontal, const float &vertical, const float &turn_flat);
	virtual void pointCam(glm::vec3 position, glm::vec3 up, glm::vec3 front, const float &yaw, const float &pitch, const float &zoom);
	virtual void updateCam();
	virtual void setViewCam();
};

#endif