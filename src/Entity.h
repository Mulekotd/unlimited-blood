#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Entity {
public:
    Entity(int x, int y, int width, int height);
    ~Entity();

    // Methods to access and modify attributes
    int getLife() const;
    void setLife(int life);
    float getSpeed() const;
    void setSpeed(float speed);
    float getStrength() const;
    void setStrength(float strength);

    // Method to draw the entity
    void draw(SDL_Renderer* renderer) const;

protected:
    // Position and size of the player
    int x, y;       // Position
    int width, height; // Size

private:
    int life;
    float speed;
    float strength;
};
