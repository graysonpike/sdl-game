#ifndef SDL_BOILERPLATE_H
#define SDL_BOILERPLATE_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Width and height of the game window in px
#define WIDTH (640)
#define HEIGHT (480)

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern TTF_Font *font_inconsolata;

void graphics_init();

void graphics_quit();

// Load image into texture from res directory.
// Filename is concatenated to RES_DIR (typically res/images/)
// Returns false if loading failed
bool load_texture(SDL_Texture **texture, std::string filename);

// Draws text onto a texture with given font and color, sets font_width and font_height to reflect that new texture
// Returns false if loading failed
bool load_font_texture(SDL_Texture **texture, TTF_Font *font, std::string text, SDL_Color text_color);

#endif