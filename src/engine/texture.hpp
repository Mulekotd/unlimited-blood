#pragma once

#include <iostream>
#include <SDL2/SDL.h>

struct Texture {
    SDL_Texture* texture = nullptr;

    SDL_Texture* load(const std::string& file_path, SDL_Renderer* renderer);
    void destroy();
};
