#include <stdio.h>
#include <SDL2/SDL.h>

#include "src/Player.h"
#include "src/Globals.h"
#include "src/Camera.h"

bool isRunning = true;

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

Player* player = nullptr;
Camera* camera = nullptr;

// Initializes SDL, creates the window and renderer
bool initialize_window() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "ERROR: Could not initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow(
        "Unlimited Blood", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        currentResolution.width, 
        currentResolution.height, 
        SDL_WINDOW_ALLOW_HIGHDPI
    );
    
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

// Setup: Initializes the game environment
void setup() {
    player = new Player();
    camera = new Camera(currentResolution.width, currentResolution.height);

    // Update the screen center based on the initial resolution
    updateScreenCenter();
}

// Processes input events from the SDL event queue
void process_events() {
    SDL_Event event;

    // Process all events in the event queue
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        
        player->inputs(event);
    }
}

// Update: Updates the game state
void update() {
    process_events();
    camera->follow(*player);
}

// Render: draws the player, and presents the updated frame
void render() {
    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
    SDL_RenderClear(gRenderer);

    // Get camera offsets to adjust rendering position
    int offsetX = camera->getOffsetX();
    int offsetY = camera->getOffsetY();

    // Draw the player with the camera's offset
    player->draw(gRenderer, 255, 0, 0, 255, offsetX, offsetY);

    SDL_RenderPresent(gRenderer);
}

// Destroys the window and renderer, then quits SDL
void destroy_window() {
    delete player;
    delete camera;

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    
    gWindow = nullptr;
    gRenderer = nullptr;
    
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    isRunning = initialize_window();
    setup();

    Uint32 frameStart;
    int frameTime;
    
    // Game loop: process events, update game state, and render
    while (isRunning) {
        frameStart = SDL_GetTicks();
        
        update();
        render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (FRAME_DURATION > frameTime) {
            SDL_Delay(FRAME_DURATION - frameTime);
        }
    }

    destroy_window();

    return EXIT_SUCCESS;
}
