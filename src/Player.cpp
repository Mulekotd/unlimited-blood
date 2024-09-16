#include "player.hpp"

Texture texture;

Player::Player(SDL_Renderer* renderer)
    : Entity(SCREEN_CENTER_X, SCREEN_CENTER_Y, 50, 50) {
        speed = 5.0f;

        m_texture = texture.load("assets/player_spritesheet_50x50.bmp", renderer);

        if (!m_texture) {
            fprintf(stderr, "Failed to load player sprite. %s/n");
        }
}

Player::~Player() {
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
}

void Player::draw(SDL_Renderer* renderer, int offsetX, int offsetY) {
    if (!m_texture) return;

    // Define a área onde o sprite será renderizado
    SDL_Rect dest_rect;
    dest_rect.x = static_cast<int>(position.x) - offsetX;
    dest_rect.y = static_cast<int>(position.y) - offsetY;
    dest_rect.w = 50;
    dest_rect.h = 50;

    // Renderiza a textura na posição do jogador
    SDL_RenderCopy(renderer, m_texture, nullptr, &dest_rect);
}

void Player::move(Vector2 direction) {
    if (direction.magnitude() > 0.0f) {
        direction.normalize();
    }

    position.x += direction.x * speed;
    position.y += direction.y * speed;
}

// TODO: add dash feature

void Player::inputs(const SDL_Event& event) {
    Vector2 direction = {0.0f, 0.0f};

    // Detect multiple keys being pressed
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
        direction.x -= 1.0f;
    }

    if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
        direction.x += 1.0f;
    }

    if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
        direction.y -= 1.0f;
    }

    if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
        direction.y += 1.0f;
    }

    move(direction);
}