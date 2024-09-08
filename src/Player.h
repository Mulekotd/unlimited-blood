#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Entity.h"

class Player : public Entity {
public:
    Player();
    ~Player();

    void move(float dx, float dy);
    void inputs(const SDL_Event& event);
};
