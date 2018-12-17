#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <vector>

class vector3d
{
private:
    std::vector<float> set;
public:
    vector3d();
    vector3d(const float &x, const float &y, const float &z);
    vector3d(const vector3d &other);
    vector3d& operator=(const vector3d &other);
    vector3d(vector3d &&other) noexcept;
    vector3d& operator=(vector3d &&other) noexcept;
    float& operator[](const int &index);
	float operator[](const int &index) const;
    ~vector3d() {}
};

#endif
