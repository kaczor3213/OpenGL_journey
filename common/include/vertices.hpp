#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "point.hpp"

template <typename T>
class vertices
{
private:
    std::vector<T> c_arr;
public:
    vertices() {c_arr.resize(3,0)};
    vertices(const vertices &other) : c_arr(other.c_arr) {}
    vertices& operator=(const vertices &other) {
        return *this=vertices(other);
    }
    vertices(vertices &&other) noexcept {
        c_arr = std::move(other.c_arr);
    }
    vertices& operator=(vertices &&other) noexcept {
        c_arr = std::move(other.c_arr);
        return *this;
    }
    ~vertices() {}
    int size() const {
        return c_arr.size();
    }
    T& operator[](const int &index)
    {
        return c_arr[index];
    }
    T operator[](const int &index) const
    {
        return c_arr[index];
    }
};
/* Czarek napraw to stara dupo
float **parse_to_glsl(std::vector<point> &vertices)
{
	float **parser = new float*[vertices.size()+1];
	for (int i=0; i< vertices.size()+1; i++)
		parser[i] = new float[7];

	for (int i = 0; i < vertices.size() + 1; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j < 4)
				parser[i][j] = vertices[i].coordinates[j];
			else
				parser[i][j] = vertices[i].get_color().pigments[j-3];
		}
	}
	return parser;
}
*/
#endif // !VERTICES_HPP
