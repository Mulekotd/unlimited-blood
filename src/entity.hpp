#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "engine/vector.hpp"

class Entity {
public:
    Entity(float x, float y, int width, int height);
    ~Entity();

    virtual void draw(SDL_Renderer* renderer, int offsetX, int offsetY);
    bool checkCollision(const Entity& other);

    Vector2 getPosition() const;

protected:
    Vector2 position;
    int width, height;
    float speed;

private:
    int m_life;
};
