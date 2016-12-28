#include <SDL2/SDL.h>
#include "clock.h"

void init_clock() {
    last_time = SDL_GetTicks();
}

float get_delta() {
    last_time = current_time;
    current_time = SDL_GetTicks();
    // current-last is in ms, divide by 1000 to return seconds
    return (current_time - last_time) / 1000.0f;
}