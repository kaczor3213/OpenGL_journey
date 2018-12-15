#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <string>
#include <glad.h>

enum camMov { FORWARD, BACKWARD, LEFT, RIGHT };

class camera
{
protected:
	glm::mat4 view;
	unsigned viewLoc;
	glm::vec3 camPos;
	glm::vec3 frontPos;
	glm::vec3 upPos;
	glm::vec3 worldUpPos;
	glm::vec3 right;
	float camYaw;
	float camPitch;
	float camZoom;
public:
	camera();
	camera(const camera &other);
	camera(camera &&other) noexcept;
	camera& operator=(const camera &other);
	camera& operator=(camera &&other) noexcept;
	~camera() {}
	virtual void move(const float &horizontal, const float &vertical, const float &depth);
	virtual void rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat);
	virtual void pointCam(glm::vec3 position, glm::vec3 up, glm::vec3 front, float yaw, float pitch, float zoom);
	virtual void updateCam();
	virtual void setView();
	virtual void procKeys(camMov dir, float inTime);
	virtual void procMouseMov(float xoffs, float yoffs, GLboolean constrain);
	virtual void procMouseZoom(float yoffs);
};

#endif