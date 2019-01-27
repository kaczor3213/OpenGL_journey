#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "point.hpp"

template <typename T>
class Vertices
{
private:
    std::vector<T> c_arr;
public:
	Vertices() { 
		c_arr.resize(3);
	}

	Vertices(const std::vector<T> &arr) {
		c_arr = arr;
	}

    Vertices(const Vertices &other) : c_arr(other.c_arr) {}

    Vertices& operator=(const Vertices &other) {
        return *this=Vertices(other);
    }

    Vertices(Vertices &&other) noexcept {
        c_arr = std::move(other.c_arr);
    }

    Vertices& operator=(Vertices &&other) noexcept {
        c_arr = std::move(other.c_arr);
        return *this;
    }

    ~Vertices() {}

    int size() {
        return c_arr.size();
    }

    T& operator[](const int &index) {
        return c_arr[index];
    }

    T operator[](const int &index) const {
        return c_arr[index];
    }

	void resize(const int &new_size) {
		c_arr.resize(new_size);
	}

	void push_back(const T &element) {
		c_arr.push_back(element);
	}
};

#endif
