// Grayson Pike, 2016

#include "sdl_boilerplate.h"

// extern variables from header file
SDL_Window *window;
SDL_Renderer *renderer;
TTF_Font *font_inconsolata = NULL;

bool load_font(TTF_Font **font, char *filename, int size) {
    // Combline path and filename
    char filepath[strlen(filename) + 5];
    strcpy(filepath, "res/");
    strcat(filepath, filename);
    *font = TTF_OpenFont(filepath, size);
    if(*font == NULL) {
        printf("Error loading font: %s\n", TTF_GetError());
        return false;
    }
    return true;
}

// Load all resources
void load_res() {
    load_font(&font_inconsolata, "fonts/Inconsolata/Inconsolata-Regular.ttf", 18);
}

// Initialize SDL (return true if successful, false otherwise)
void graphics_init() {

    // Initialize SDL_video
    if(SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER) < 0) {
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

    // Initialize TTF
    if(TTF_Init() == -1) {
        printf("SDL_ttf failed to initialize: %s\n", TTF_GetError());
        return;
    }

    load_res();
}

void graphics_quit() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

bool load_font_texture(SDL_Texture **texture, TTF_Font *font, char *text, SDL_Color text_color, int *font_width, int *font_height){
    *texture = NULL;
    SDL_Surface *loaded_surface = NULL;
    // Load surface and convert to texture
    // TTF_RenderText_Solid = quick & dirty
    // TTF_RenderText_Shaded = slow & antialiased, but with opaque box
    // TTF_RenderText_Blended = very slow & antialiased with alpha blending
    loaded_surface = TTF_RenderText_Blended(font, text, text_color);
    if(loaded_surface == NULL) {
        printf("Error loading font surface: %s\n", TTF_GetError());
        return false;
    }
    *texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if(*texture == NULL) {
        printf("Unable to create texture from surface: %s\n", SDL_GetError());
    }
    *font_width = loaded_surface->w;
    *font_height = loaded_surface->h;
    SDL_FreeSurface(loaded_surface);
    return true;
}