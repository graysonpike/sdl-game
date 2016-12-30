/*
Grayson Pike, 2016
SDL Boilerplate contains functions and variables for SDL2,
such as initialization and termination
*/

#ifndef SDL_BOILERPLATE_H
#define SDL_BOILERPLATE_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WIDTH (640)
#define HEIGHT (480)

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern TTF_Font *font_inconsolata;

// Initialize SDL (return true if successful, false otherwise)
void graphics_init();
void graphics_quit();
bool load_font_texture(SDL_Texture **texture, TTF_Font *font, char *text, SDL_Color text_color, int *font_width, int *font_height);

#endif