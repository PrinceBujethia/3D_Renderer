#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "raylib.h"
#include <cmath>

class Vector3D{
    public:
    float x, y, z;

    Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z){}

    Vector3D operator+(const Vector3D& other) const{
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const{
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }
    
    Vector3D operator*(float scalar) const{
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    float Dot(const Vector3D& other) const{
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3D Cross(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    float Length() const {
        return sqrt(x * x + y * y + z * z);
    }
    
    Vector3D Normalize() const {
        float len = Length();
        if (len == 0) return Vector3D(0, 0, 0);
        return Vector3D(x / len, y / len, z / len);
    }
    
    Vector3 ToRaylib() const {
        return {x, y, z};
    }
};

#endif