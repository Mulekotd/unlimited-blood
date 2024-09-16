#include "texture.hpp"

SDL_Texture* Texture::load(const std::string& file_path, SDL_Renderer* renderer) {
    SDL_Surface* surface = SDL_LoadBMP(file_path.c_str());

    if (!surface) {
        fprintf(stderr, "Failed to load image: %s\n", SDL_GetError());
        return nullptr;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        fprintf(stderr, "Failed to create texture:  %s\n", SDL_GetError());
    }

    return texture;
}

void Texture::destroy() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
