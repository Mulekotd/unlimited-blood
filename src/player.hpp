#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "entity.hpp"
#include "engine/globals.hpp"
#include "engine/texture.hpp"
#include "engine/vector.hpp"

class Player : public Entity {
public:
    Player(SDL_Renderer* renderer);
    ~Player();

    void move(Vector2 direction);
    void inputs(const SDL_Event& event);

    void draw(SDL_Renderer* renderer, int offsetX, int offsetY) override;

private:
    SDL_Texture* m_texture;
};
