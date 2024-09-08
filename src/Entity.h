#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Entity {
public:
    Entity(int x, int y, int width, int height);
    ~Entity();

    void draw(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int offsetX, int offsetY);
    bool checkCollision(const Entity& other);

    SDL_Point getCoordinates() const;

protected:
    int x, y;
    int width, height;
    float speed;  

private:
    int life;
};
