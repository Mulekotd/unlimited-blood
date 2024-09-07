#include "Entity.h"

// Construtor
Entity::Entity(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height), life(100), speed(0.0f), strength(0.0f) {
}

// Destrutor
Entity::~Entity() {}

int Entity::getLife() const {
    return this->life;
}

void Entity::setLife(int life) {
    this->life = life;
}

float Entity::getSpeed() const {
    return this->speed;
}

void Entity::setSpeed(float speed) {
    this->speed = speed;
}

float Entity::getStrength() const {
    return this->strength;
}

void Entity::setStrength(float strength) {
    this->strength = strength;
}

// Method for drawing an entity
void Entity::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_Rect rectangle = { x, y, width, height };

    SDL_RenderFillRect(renderer, &rectangle);
}
