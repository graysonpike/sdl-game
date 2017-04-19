#include "font_renderer.h"

FontRenderer::FontRenderer(SDL_Renderer *renderer, Resources *resources) {
    this->renderer = renderer;
    this->resources = resources;
}

// Draws text to a blank surface and transfers that to the given texture
bool FontRenderer::load_font_texture(SDL_Texture **texture, std::string font,
                                     std::string text, SDL_Color text_color) {

    // Assume texture is empty
    *texture = NULL;

    
    // Load temporary surface and convert to texture
    SDL_Surface *loaded_surface = NULL;
    // TTF_RenderText_Solid = quick & dirty
    // TTF_RenderText_Shaded = slow & antialiased, but with opaque box
    // TTF_RenderText_Blended = very slow & antialiased with alpha blending
    loaded_surface = TTF_RenderText_Blended(resources->get_font(font), text.c_str(), text_color);
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