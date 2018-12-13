#ifndef CAMERA_HPP
#define CAMERA_HPP

/*
Klasa kamery będzie o wiele bardziej rozbudowana.
Proponuję przebudowanie całej na wzór tej stworzonej przez gościa z kursu.
viewLoc może tu istnieć, pod warunkiem, że klasa camera będzie miała dostęp do bufora. 
Jest tak, ponieważ potrzebuje ona dostępu do programu shadera (alternatywą jest przeniesienie viewLoc i pochodnych do shape).
*/

#include <glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class camera
{
protected:
	glm::mat4 view;
	unsigned viewLoc;
public:
	camera();
	camera(const camera &other);
	camera(camera &&other) noexcept;
	camera& operator=(const camera &other);
	camera& operator=(camera &&other) noexcept;
	~camera() {}
	virtual void move(const float &horizontal, const float &vertical, const float &depth);
	virtual void rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat);
	virtual void zoom(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter);
};

#endif