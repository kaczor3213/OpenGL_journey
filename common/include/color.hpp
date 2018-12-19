#ifndef COLOR_HPP
#define COLOR_HPP

#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

class Color
{
private:
	std::stringstream buffer;
	bool check_range(const unsigned &VALUE);
public:
	std::vector <float> pigments;
	Color () {}
	Color(const unsigned &RED,
		const unsigned &GREEN,
		const unsigned &BLUE,
		const unsigned &ALPHA);
	Color(const Color &other);
	Color& operator=(const Color &other);
	Color(Color &&other) noexcept;
	Color& operator=(Color &&other) noexcept;
	~Color();
	void set_color(const unsigned &RED,
		const unsigned &GREEN,
		const unsigned &BLUE,
		const unsigned &ALPHA);
};
/*

extern const color COLOR_GREEN(0, 255, 0, 0);
extern const color COLOR_BLUE(0, 0, 255, 0);
extern const color COLOR_BLACK(0, 0, 0, 0);
extern const color COLOR_WHITE(255, 255, 255, 0);


#define COLOR_RED color(255, 0, 0, 0);
#define COLOR_BLUE color(0, 0, 255, 0);
#define COLOR_BLACK color(0, 0, 0, 0);
#define COLOR_WHITE color(255, 255, 255, 0);
*/

#endif // !COLOR_HPP


