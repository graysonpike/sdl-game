// Program to figure out how SDL_GetPerformanceCounter works

#include <SDL2/SDL.h>
#include <stdbool.h>

#define BOGUS 100

void init() {
    // Initialize SDL_video
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return;
    }
}

int main() {

    Uint64 last_time;
    Uint64 now_time = SDL_GetPerformanceCounter();
    double delta;
    double total_time = 0;

    while(true) {
        last_time = now_time;
        now_time = SDL_GetPerformanceCounter();
        delta = (now_time - last_time) / (double) SDL_GetPerformanceFrequency();
        total_time += delta;
        printf("TOTAL TIME: %lf\n", total_time);
    }

}