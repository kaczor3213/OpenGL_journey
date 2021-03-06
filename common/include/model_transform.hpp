#ifndef MODEL_TRANSFORM_HPP
#define MODEL_TRANSFORM_HPP

#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <vector>
#include <cmath>

# define M_PI	3.141592653
#define X_AXIS	(glm::vec3(1, 0, 0))
#define Y_AXIS	(glm::vec3(0, 1, 0))
#define Z_AXIS	(glm::vec3(0, 0, 1))

class ModelTransform
{
protected:
	float phaseX;
	float phaseY;
	float phaseZ;
	float sum;
	glm::mat4 transform;
	glm::mat4 m_rotation;
	glm::mat4 m_position;
	glm::vec3 vMove;
	glm::vec3 vCurrentPosition;
	unsigned transformLoc;
	void calc_phase_by_x();
	void calc_phase_by_y();
	void calc_phase_by_z();
public:
	float cycle;
	ModelTransform();
	ModelTransform(const ModelTransform &other);
	ModelTransform(ModelTransform &&other) noexcept;
	ModelTransform& operator=(const ModelTransform &other);
	ModelTransform& operator=(ModelTransform &&other) noexcept;
	~ModelTransform() {}
	virtual void move(const float &horizontal, const float &vertical, const float &depth);
	virtual void roll(const float& degrees);
	virtual void yaw(const float& degrees);
	virtual void pitch(const float& degrees);
	virtual void move_by_x(const glm::vec3& t_point, float degrees);
	virtual void move_by_y(const glm::vec3& t_point, float degrees);
	virtual void move_by_z(const glm::vec3& t_point, float degrees);
	virtual void transformation();
	virtual void scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter);
	virtual void scale_whole(const float &scale_parameter);
};

#endif