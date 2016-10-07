/*
Grayson Pike, 2016
SDL Boilerplate contains functions and variables for SDL2,
such as initialization and termination
*/

#ifndef SDL_BOILERPLATE_H
#define SDL_BOILERPLATE_H

#include <SDL2/SDL.h>

#define WIDTH 640
#define HEIGHT 480

extern SDL_Window *window;
extern SDL_Renderer *renderer;

// Initialize SDL (return true if successful, false otherwise)
void graphics_init();
void graphics_quit();

#endif