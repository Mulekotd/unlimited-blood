#include "Entity.h"

Entity::Entity(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height), speed(0.0f), life(0), strength(0.0f) {}

Entity::~Entity() {}

SDL_Point Entity::getCoordinates() const {
    return SDL_Point{ x, y };
}

bool Entity::checkCollision(const Entity& other) {
    // Simple AABB collision detection
    return !(x + width < other.x || x > other.x + other.width ||
             y + height < other.y || y > other.y + other.height);
}

void Entity::draw(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int offsetX, int offsetY) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_Rect rect = { x - offsetX, y - offsetY, width, height };
    SDL_RenderFillRect(renderer, &rect);
}
