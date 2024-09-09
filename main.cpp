#include "src/game.hpp"

Uint32 frameStart;
int frameTime;

int main(int argc, char* argv[]) {
    Game game;

    if (!game.initialize()) {
        return EXIT_FAILURE;
    }

    game.setup();

    // Game loop: process events, update game state, and render
    while (game.isRunning()) {
        frameStart = SDL_GetTicks();

        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;

        if (FRAME_DURATION > frameTime) {
            SDL_Delay(FRAME_DURATION - frameTime);
        }
    }

    game.clean();

    return EXIT_SUCCESS;
}
