#include <SDL2/SDL.h>

#include "camera.hpp"
#include "entity.hpp"
#include "globals.hpp"

Camera::Camera(int screenWidth, int screenHeight) 
    : m_cx(0), m_cy(0), m_screenWidth(screenWidth), m_screenHeight(screenHeight) {}

Camera::~Camera() {}

// Smoothly follow the entity with a slight delay
void Camera::follow(const Entity& entity) {
    SDL_Point coords = entity.getCoordinates();

    // Target position: center the entity on screen
    int targetX = coords.x - SCREEN_CENTER_X;
    int targetY = coords.y - SCREEN_CENTER_Y;

    // Smoothly move the camera position towards the target using linear interpolation
    m_cx += static_cast<int>((targetX - m_cx) * m_smoothSpeed);
    m_cy += static_cast<int>((targetY - m_cy) * m_smoothSpeed);
}

// Get the camera's X offset for rendering adjustment
int Camera::getOffsetX() const {
    return m_cx;
}

// Get the camera's Y offset for rendering adjustment
int Camera::getOffsetY() const {
    return m_cy;
}
