#include "game.hpp"

Game::Game() 
    : m_isRunning(false), m_window(nullptr), m_renderer(nullptr), 
      m_player(nullptr), m_camera(nullptr) {}

Game::~Game() {
    clean();
}

bool Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "ERROR: Could not initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    m_window = SDL_CreateWindow(
        "Unlimited Blood", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        currentResolution.width, 
        currentResolution.height, 
        SDL_WINDOW_ALLOW_HIGHDPI
    );
    
    if (m_window == nullptr) {
        fprintf(stderr, "ERROR: Could not create window: %s\n", SDL_GetError());
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    
    if (m_renderer == nullptr) {
        fprintf(stderr, "ERROR: Could not create renderer: %s\n", SDL_GetError());
        return false;
    }

    m_isRunning = true;
    return true;
}

void Game::setup() {
    m_player = new Player(m_renderer);
    m_camera = new Camera(currentResolution.width, currentResolution.height);
    
    updateScreenCenter();
}

void Game::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            m_isRunning = false;
        }
        
        m_player->inputs(event);
    }
}

void Game::update() {
    handleEvents();
    m_camera->follow(*m_player);
}

void Game::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    SDL_RenderClear(m_renderer);

    int offsetX = m_camera->getOffsetX();
    int offsetY = m_camera->getOffsetY();

    m_player->draw(m_renderer, offsetX, offsetY);

    SDL_RenderPresent(m_renderer);
}

void Game::clean() {
    delete m_player;
    delete m_camera;

    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);

    m_window = nullptr;
    m_renderer = nullptr;

    SDL_Quit();
}

bool Game::isRunning() const {
    return m_isRunning;
}
