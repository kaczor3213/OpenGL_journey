//
// Created by Moew34 on 11/17/2018.
//
#include "../include/triangle.hpp"
///prepare for proper indices arrays


triangle::triangle() {
	indices = std::vector<unsigned>{ 0,1,2 };
	coordinates.resize(3);
}

triangle::triangle(const triangle &other) {
	indices = other.indices;
    coordinates = other.coordinates;
}

triangle::triangle(triangle &&other) noexcept {
	indices = std::move(other.indices);
    coordinates = std::move(other.coordinates);
}

triangle& triangle::operator=(const triangle &other) {
    return *this = triangle(other);
}

triangle& triangle::operator=(triangle &&other) noexcept {
	indices = std::move(other.indices);
    coordinates = std::move(other.coordinates);
    return *this;
}

