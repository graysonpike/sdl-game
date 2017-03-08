#include "graphics.h"

const int Graphics::WIDTH = 640, Graphics::HEIGHT = 480;

Graphics::Graphics() {
	init_sdl();
    resources = new Resources(renderer);
    resources->load_resources();
    font_renderer = new FontRenderer(renderer, resources);
    overlay = new Overlay(renderer);
    fps_counter = FPSCounter();
}

bool Graphics::init_sdl() {

    // Initialize SDL_video
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return false;
    }
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

    // Initialize Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL) {
        printf("Could not init renderer: %s\n", SDL_GetError());
        return false;
    }

    // Initialize TTF
    if(TTF_Init() == -1) {
        printf("SDL_ttf failed to initialize: %s\n", TTF_GetError());
        return false;
    }

    //load_resources();
    return true;
}

Graphics::~Graphics() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete resources;
    delete font_renderer;
    delete overlay;
}

void Graphics::render_entities(std::vector<Entity*> *entities, float delta) {
    for(int i = 0; i < entities->size(); i++) {
        (*entities)[i]->render(renderer, resources, delta);
    }
}

void Graphics::render_overlay() {
    overlay->render_fps(font_renderer, lround(fps_counter.get_fps()));
}

void Graphics::present_renderer(float delta) {
	SDL_RenderPresent(renderer);
    fps_counter.count(delta);
}

void Graphics::clear_screen() {
    // Clear the screen with a white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
};