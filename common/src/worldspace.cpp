/*#include "../include/worldspace.hpp"

worldspace::worldspace() {
	projection = glm::mat4(1.0f);
}

worldspace::worldspace(const worldspace &other) {
	projection = other.projection;
}

worldspace::worldspace(worldspace &&other) noexcept {
	projection = std::move(other.projection);
}

worldspace& worldspace::operator=(const worldspace &other) {
	return *this = worldspace(other);
}

worldspace& worldspace::operator=(worldspace &&other) noexcept {
	projection = std::move(other.projection);
	return *this;
}

void worldspace::set_projection(const float &angle, const float &scr_width, const float &scr_height) {
	projection = glm::perspective(glm::radians(angle), (float)scr_width/(float)scr_height, 0.1f, 100.0f);
}
*/