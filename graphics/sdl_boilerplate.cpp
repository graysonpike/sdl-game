#include "sdl_boilerplate.h"
#include "resources.h"

#define RES_DIR "res/"

// extern variables from header file
SDL_Window *window;
SDL_Renderer *renderer;

bool load_texture(SDL_Texture **texture, std::string filename){
    // Assumes texture is not already created
    *texture = NULL;
    // Imagefile -> Surface -> Texture
    // Empty surface to begin with
    SDL_Surface *loaded_surface = NULL;
    // Concatenate filename to resource directory
    std::string filepath = std::string(RES_DIR) + "images/" + filename;
    // Load imagefile into surface
    loaded_surface = IMG_Load(filepath.c_str());
    // Check first to see if the load failed
    if(loaded_surface == NULL) {
        printf("Error loading image: %s\n", SDL_GetError());
        return false;
    }
    // If successful, transfer the surface into the texture
    *texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if(texture == NULL) {
        printf("Unable to create texture from surface: %s\n", SDL_GetError());
    }
    // Free the temporary surface
    SDL_FreeSurface(loaded_surface);
    return true;
}

bool load_font(TTF_Font **font, std::string filename, int size) {
    // Concatenate filename to resource directory
    std::string filepath = std::string(RES_DIR) + "fonts/" + filename;
    *font = TTF_OpenFont(filepath.c_str(), size);
    if(*font == NULL) {
        printf("Error loading font: %s\n", TTF_GetError());
        return false;
    }
    return true;
}

// Initialize SDL (return true if successful, false otherwise)
void graphics_init() {

    // Initialize SDL_video
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return;
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
        return;
    }

    // Initialize Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL) {
        printf("Could not init renderer: %s\n", SDL_GetError());
        return;
    }

    // Initialize TTF
    if(TTF_Init() == -1) {
        printf("SDL_ttf failed to initialize: %s\n", TTF_GetError());
        return;
    }

    load_resources();

}

void graphics_quit() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

// Draws text to a blank surface and transfers that to the given texture
bool load_font_texture(SDL_Texture **texture, std::string font, std::string text, SDL_Color text_color){
    // Assume texture is empty
    *texture = NULL;
    SDL_Surface *loaded_surface = NULL;
    // Load surface and convert to texture
    // TTF_RenderText_Solid = quick & dirty
    // TTF_RenderText_Shaded = slow & antialiased, but with opaque box
    // TTF_RenderText_Blended = very slow & antialiased with alpha blending
    loaded_surface = TTF_RenderText_Blended(fonts[font], text.c_str(), text_color);
    if(loaded_surface == NULL) {
        printf("Error loading font surface: %s\n", TTF_GetError());
        return false;
    }
    // Transfer surface to texture
    *texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if(*texture == NULL) {
        printf("Unable to create texture from surface: %s\n", SDL_GetError());
    }
    // Free temporary surface and exit
    SDL_FreeSurface(loaded_surface);
    return true;
}