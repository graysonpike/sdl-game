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
    SDL_Color color = {255, 255, 255, 255};

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