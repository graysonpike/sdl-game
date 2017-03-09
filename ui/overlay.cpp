#include "overlay.h"
#include <cmath>

Overlay::Overlay(int width, int height, SDL_Renderer *renderer, Resources *resources) {
    this->renderer = renderer;
    this->resources = resources;
    this->width = width;
    this->height = height;
}


void Overlay::render_fps(FontRenderer *font_renderer, int fps) {

    // Texture to hold the drawn text
    SDL_Texture *text_texture = NULL;
    int text_width;
    int text_height;
    SDL_Color color = {0, 0, 0, 255};

    // TODO: Round instead of truncate
    std::string text = "FPS: " + std::to_string(std::lround(fps));

    font_renderer->load_font_texture(&text_texture, "inconsolata", text, color);
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

void Overlay::render_health(int health, int max_health) {
    // Get textures to be used: full and empty heart icons
    SDL_Texture *full_heart = resources->get_texture("full_heart");
    SDL_Texture *empty_heart = resources->get_texture("empty_heart");
    // Draw hearts from top left of screen
    for(int i = 0; i < max_health; i++) {
        SDL_Rect dst = {
            width - i * (32 + 16) - 16 - 32,
            16,
            32,
            32
        };
        if(health < i+1) {
            SDL_RenderCopy(renderer, empty_heart, NULL, &dst);
        } else {
            SDL_RenderCopy(renderer, full_heart, NULL, &dst);
        }
    }
}