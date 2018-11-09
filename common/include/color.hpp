#ifndef COLOR_HPP
#define COLOR_HPP


#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

class color
{
private:
	std::stringstream buffer;
	bool check_range(const unsigned &VALUE);
	void generate_buffer();
public:
	std::vector<float> pigments;
	color () {}
	color(const unsigned &RED,
		const unsigned &GREEN,
		const unsigned &BLUE,
		const unsigned &ALPHA);
	color(const color &other);
	color& operator=(const color &other);
	color(color &&other) noexcept;
	color& operator=(color &&other) noexcept;
	~color();
	std::string get_buffer();
	void set_color(const unsigned &RED,
		const unsigned &GREEN,
		const unsigned &BLUE,
		const unsigned &ALPHA);
};



#endif // !COLOR_H