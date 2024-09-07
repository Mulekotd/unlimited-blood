#include <stdio.h>
#include <SDL2/SDL.h>

#include "src/Player.h"
#include "src/Globals.h"

bool isRunning = true;

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

Player player;

// Initializes SDL, creates window and renderer
bool initialize_window() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "ERROR: Could not initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow("Unlimited Blood", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, currentResolution.width, currentResolution.height, SDL_WINDOW_ALLOW_HIGHDPI);
    
    if (gWindow == nullptr) {
        fprintf(stderr, "ERROR: Could not create window: %s\n", SDL_GetError());
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    
    if (gRenderer == nullptr) {
        fprintf(stderr, "ERROR: Could not create renderer: %s\n", SDL_GetError());
        return false;
    }
    
    return true;
}

// Setup: Sets up the game environment
void setup() {
    player = Player();
}

// Update: handles events
void update() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (SDL_QUIT == event.type) {
            isRunning = false;
        }
    }

}

// Render: draws the player and updates the screen
void render(void) {
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);

    player.draw(gRenderer);

    SDL_RenderPresent(gRenderer);
}

void destroy_window() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    
    gWindow = nullptr;
    gRenderer = nullptr;
    
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    isRunning = initialize_window();
    setup();

    while (isRunning) {
        update();
        render();
    }

    destroy_window();

    return EXIT_SUCCESS;
}
