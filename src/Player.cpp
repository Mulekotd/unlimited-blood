#include <iostream>
#include <math.h>

#include "player.hpp"
#include "globals.hpp"

Player::Player(void)
    : Entity(SCREEN_CENTER_X, SCREEN_CENTER_Y, 50, 50) {
        speed = 5.0f;
}

Player::~Player() {}

// TODO: fix "shaking" character
void Player::move(float dx, float dy) {
    // Normalize the vector to prevent faster movement in diagonals
    float magnitude = sqrt(dx * dx + dy * dy);
    
    if (magnitude != 0) {
        dx /= magnitude;
        dy /= magnitude;
    }

    x += dx * speed;
    y += dy * speed;
}

// TODO: add dash feature
void Player::inputs(const SDL_Event& event) {
    float dx = 0.0f;
    float dy = 0.0f;

    // Detect multiple keys being pressed
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
        dx -= 1.0f;
    }
    if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
        dx += 1.0f;
    }
    if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
        dy -= 1.0f;
    }
    if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
        dy += 1.0f;
    }

    move(dx, dy);
}
