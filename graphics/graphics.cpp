#include "graphics.h"

const int Graphics::WIDTH = 640, Graphics::HEIGHT = 480;

Graphics::Graphics() : resources(renderer) {
	init_sdl();
	fps = 69;
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
}

// Draws text to a blank surface and transfers that to the given texture
bool Graphics::load_font_texture(SDL_Texture **texture, std::string font, std::string text, SDL_Color text_color){
    // Assume texture is empty
    *texture = NULL;
    SDL_Surface *loaded_surface = NULL;
    // Load surface and convert to texture
    // TTF_RenderText_Solid = quick & dirty
    // TTF_RenderText_Shaded = slow & antialiased, but with opaque box
    // TTF_RenderText_Blended = very slow & antialiased with alpha blending
    loaded_surface = TTF_RenderText_Blended(resources.get_font(font), text.c_str(), text_color);
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

void Graphics::render_fps() {

    // Texture to hold the drawn text
    SDL_Texture *text_texture = NULL;
    int text_width;
    int text_height;
    SDL_Color color = {0, 0, 0, 255};

    std::string text = "FPS: " + std::to_string(fps);

    load_font_texture(&text_texture, "inconsolata", text, color);
    SDL_QueryTexture(text_texture, NULL, NULL, &text_width, &text_height);

    SDL_Rect dst = {
        16,
        16,
        text_width,
        text_height
    };

    SDL_RenderCopy(renderer, text_texture, NULL, &dst);

    SDL_DestroyTexture(text_texture);
}

void Graphics::present_renderer(){
	SDL_RenderPresent(renderer);
}

void Graphics::clear_screen() {
    // Clear the screen with a white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
};