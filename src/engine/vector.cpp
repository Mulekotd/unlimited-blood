#include "vector.hpp"

// Adds two 2D vectors
Vector2 Vector2::add(const Vector2& other) const {
    return { x + other.x, y + other.y };
}

// Subtracts another 2D vector from this one
Vector2 Vector2::subtract(const Vector2& other) const {
    return { x - other.x, y - other.y };
}

// Scales this 2D vector by a scalar value
Vector2 Vector2::scale(float scalar) const {
    return { x * scalar, y * scalar };
}

// Calculates the magnitude of the 2D vector
float Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

// Normalizes the 2D vector
void Vector2::normalize() {
    float length = this->magnitude();
    if (length != 0) {
        x /= length;
        y /= length;
    }
}

// Adds two 3D vectors
Vector3 Vector3::add(const Vector3& other) const {
    return { x + other.x, y + other.y, z + other.z };
}

// Subtracts another 3D vector from this one
Vector3 Vector3::subtract(const Vector3& other) const {
    return { x - other.x, y - other.y, z - other.z };
}

// Scales this 3D vector by a scalar value
Vector3 Vector3::scale(float scalar) const {
    return { x * scalar, y * scalar, z * scalar };
}

// Calculates the magnitude of the 3D vector
float Vector3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Normalizes the 3D vector
void Vector3::normalize() {
    float length = this->magnitude();
    if (length != 0) {
        x /= length;
        y /= length;
        z /= length;
    }
}
