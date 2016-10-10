// Grayson Pike, 2016

#include "sdl_boilerplate.h"

// extern variables from header file
SDL_Window *window;
SDL_Renderer *renderer;

// Initialize SDL (return true if successful, false otherwise)
void graphics_init() {

    // Initialize SDL_video
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return;
    }
    window = SDL_CreateWindow(
        "SDL2 Game",             // window title
        SDL_WINDOWPOS_UNDEFINED,      // initial x position
        SDL_WINDOWPOS_UNDEFINED,      // initial y position
        WIDTH,                        // width, in pixels
        HEIGHT,                       // height, in pixels
        SDL_WINDOW_OPENGL             // flags - see below
    );
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }

    // Initialize Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        printf("Could not init renderer: %s\n", SDL_GetError());
        return;
    }
}

void graphics_quit() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}
