#include "graphics.h"
#include "../entities/player.h"

// STATIC MEMBERS

const int Graphics::WIDTH = 800, Graphics::HEIGHT = 800;

// PRIVATE HELPER FUNCTIONS

bool Graphics::init_sdl() {

    // Initialize SDL_video
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return false;
    }

    // Create SDL Window
    window = SDL_CreateWindow(
        "SDL2 Game",                  // window title
        SDL_WINDOWPOS_UNDEFINED,      // initial x position
        SDL_WINDOWPOS_UNDEFINED,      // initial y position
        WIDTH,                        // width, in pixels
        HEIGHT,                       // height, in pixels
        SDL_WINDOW_OPENGL             // flags - see below
    );
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    // Initialize renderer with flags
    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL) {
        printf("Could not init renderer: %s\n", SDL_GetError());
        return false;
    }

    // Initialize TTF
    if(TTF_Init() == -1) {
        printf("SDL_ttf failed to initialize: %s\n", TTF_GetError());
        return false;
    }

    return true;

}

// PUBLIC FUNCTIONS

Graphics::Graphics() {

	init_sdl();
    resources = new Resources(renderer);
    resources->load_resources();
    font_renderer = new FontRenderer(renderer, resources);
    overlay = new Overlay(WIDTH, HEIGHT, renderer, resources);
    fps_counter = FPSCounter();

}

void Graphics::clear_screen() {

    // Clear the screen with a black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

};

void Graphics::render_overlay(std::vector<Entity*> *entities) {

    Player *player = (Player*)(*entities)[0];
    overlay->render_fps(font_renderer, lround(fps_counter.get_fps()));

}

void Graphics::present_renderer(float delta) {

	SDL_RenderPresent(renderer);
    fps_counter.count(delta);

}

void Graphics::render_entities(std::vector<Entity*> *entities, float delta) {

    for(int i = 0; i < entities->size(); i++) {
        (*entities)[i]->render(renderer, resources, delta);
    }
    
}

int Graphics::get_width() {
    return WIDTH;
}

int Graphics::get_height() {
    return HEIGHT;
}

Graphics::~Graphics() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete resources;
    delete font_renderer;
    delete overlay;

}