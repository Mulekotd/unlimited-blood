#pragma once

#include "entity.hpp"

class Camera {
public:
    Camera(int screenWidth, int screenHeight);
    ~Camera();
    
    void follow(const Entity& entity);
    int getOffsetX() const;
    int getOffsetY() const;

private:
    int m_cx, m_cy;
    int m_screenWidth, m_screenHeight;
    float m_smoothSpeed = 0.05f;
};
