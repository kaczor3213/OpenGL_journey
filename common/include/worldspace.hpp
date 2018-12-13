#ifndef WORLDSPACE_HPP
#define WORLDSPACE_HPP

#include <glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class worldspace
{
protected:
	glm::mat4 projection;
	unsigned int projectionLoc;
public:
	worldspace();
	worldspace(const worldspace &other);
	worldspace(worldspace &&other) noexcept;
	worldspace& operator=(const worldspace &other);
	worldspace& operator=(worldspace &&other) noexcept;
	~worldspace() {}
	virtual void set_projection(const float &angle, const float &scr_width, const float &scr_height);
};
#endif // !WORLDSPACE_HPP
