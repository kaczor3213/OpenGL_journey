#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <string>
#include "vector2d.hpp"

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

enum CameraMovement { FORWARD, BACKWARD, LEFT, RIGHT };

class camera
{
private:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	float Yaw;
	float Pitch;
	float Zoom;

	float MovementSpeed;
	float MouseSensitivity;
protected:
	unsigned viewLoc;
	glm::mat4 view;
	unsigned projectionLoc;
	glm::mat4 projection;
public:
	camera();
	camera(const camera &other);
	camera(camera &&other) noexcept;
	camera& operator=(const camera &other);
	camera& operator=(camera &&other) noexcept;
	~camera() {}
	void get_view();
	void update();
	virtual void move(const float &horizontal, const float &vertical, const float &depth);
	virtual void rotate(const float &speed_scale, const float &horizontal, const float &vertical, const float &turn_flat);
	virtual void place(glm::vec3 position, glm::vec3 up, glm::vec3 front, const float &yaw, const float &pitch, const float &zoom);


	virtual void process_keyboard(CameraMovement direction, const float &deltaTime);
	virtual void process_mouse_movement(const float &xoffset, const float &yoffset, bool constrainPitch);
	virtual void process_mouse_movement(const vector2d &offset, bool constrainPitch);
	virtual void process_mouse_scroll(double yoffset);
};

#endif