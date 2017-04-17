#include <SDL2/SDL.h>
#include "clock.h"

Clock::Clock() {
    last_time = SDL_GetTicks();
}

void Clock::reset() {
	last_time = SDL_GetTicks();
}

void Clock::tick() {

    float current_time = SDL_GetTicks();
    // current-last is in ms, divide by 1000 to return seconds
    delta = (current_time - last_time) / 1000.0f;
    last_time = current_time;
    
}

float Clock::get_delta() {
    return delta;
}