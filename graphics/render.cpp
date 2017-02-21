#include "render.h"

const std::string Renderer::res_dir = "res/";

Renderer::Renderer() {

}

void Renderer::clear_screen() {
    // Clear the screen with a white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
};

void Renderer::render_fps() {

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
}