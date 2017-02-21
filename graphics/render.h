#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#define NUM_AVGD_FRAMES (10)

class Renderer {

    static const int width = 640;
    static const int height = 480;
    static const std::string res_dir;

    SDL_Window *window;
    SDL_Renderer *renderer;

    bool load_font(TTF_Font **font, std::string filename, int size);

public:

    Renderer();
    void init();
    void quit();
    void render_entities();
    void render_fps();
    void clear_screen();

    // Load image into texture from res directory.
    // Filename is concatenated to RES_DIR (typically res/images/)
    // Returns false if loading failed
    bool load_image_texture(SDL_Texture **texture, std::string filename);

    // Draws text onto a texture with given font and color
    // Returns false if loading failed
    bool load_font_texture(SDL_Texture **texture, std::string font, std::string text, SDL_Color text_color);

};

#endif