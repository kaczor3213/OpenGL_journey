#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "point.hpp"
///add vector constructor
template <typename T>
class vertices
{
private:
    std::vector<T> c_arr;
public:
	vertices() { 
		c_arr.resize(3, 0);
	}
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
#endif // !VERTICES_HPP
