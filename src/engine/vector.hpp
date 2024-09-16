#pragma once

#include <cmath>

// Structure for 2D vectors
struct Vector2 {
    float x;
    float y;

    Vector2 add(const Vector2& other) const;
    Vector2 subtract(const Vector2& other) const;
    Vector2 scale(float scalar) const;

    float magnitude() const;
    void normalize();
};

// Structure for 3D vectors
struct Vector3 {
    float x;
    float y;
    float z;

    Vector3 add(const Vector3& other) const;
    Vector3 subtract(const Vector3& other) const;
    Vector3 scale(float scalar) const;

    float magnitude() const;
    void normalize();
};
