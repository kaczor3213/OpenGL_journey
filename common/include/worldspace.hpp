#ifndef WORLDSPACE_HPP
#define WORLDSPACE_HPP

#include "../include/polygon.hpp"
class worldspace : polygon
{
protected:
	glm::mat4 view;
	glm::mat4 projection;
	int viewLoc;
	int projectionLoc;
public:
	worldspace();
	worldspace(const worldspace &other);
	worldspace(worldspace &&other) noexcept;
	worldspace& operator=(const worldspace &other);
	worldspace& operator=(worldspace &&other) noexcept;
	void set_view(const float &horizontal, const float &vertical, const float &depth);
	void set_projection(const float &angle, const float &scr_width, const float &scr_height);
	void draw_world();
	~worldspace() {}
};
#endif // !WORLDSPACE_HPP
