#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "point.hpp"

template <typename T>
class vertices
{
private:
    std::vector<T> c_arr;
public:
	vertices() { 
		c_arr.resize(3);
	}
	vertices(const std::vector<T> &arr) {
		c_arr = arr;
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
    int size() {
        return c_arr.size();
    }
    T& operator[](const int &index) {
        return c_arr[index];
    }
    T operator[](const int &index) const {
        return c_arr[index];
    }
	void resize(const int &new_size)
	{
		c_arr.resize(new_size);
	}
};
#endif // !VERTICES_HPP
