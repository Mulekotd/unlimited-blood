#include "entity.hpp"

Entity::Entity(float x, float y, int width, int height)
    : position{x, y}, width(width), height(height), speed(0.0f), m_life(0) {}

Entity::~Entity() {}

Vector2 Entity::getPosition() const {
    return position;
}

bool Entity::checkCollision(const Entity& other) {
    // Simple AABB collision detection usando Vector2 para as coordenadas
    return !(position.x + width < other.position.x || position.x > other.position.x + other.width ||
             position.y + height < other.position.y || position.y > other.position.y + other.height);
}

void Entity::draw(SDL_Renderer* renderer, int offsetX, int offsetY) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_Rect rect = { static_cast<int>(position.x) - offsetX, static_cast<int>(position.y) - offsetY, width, height };
    SDL_RenderFillRect(renderer, &rect);
}
