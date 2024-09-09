#pragma once

#include <SDL2/SDL.h>

#include "player.hpp"
#include "camera.hpp"
#include "globals.hpp"

class Game {
public:
    Game();
    ~Game();
    
    bool initialize();
    void setup();
    void handleEvents();
    void update();
    void render();
    void clean();

    bool isRunning() const;

private:
    bool m_isRunning;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    Player* m_player;
    Camera* m_camera;
};
