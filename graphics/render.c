// Grayson Pike, 2016

#include <SDL2/SDL_ttf.h>
#include "render.h"
#include "sdl_boilerplate.h"
#include "../game/game.h"
#include "../game/block.h"
#include "../data_structure/linked_list.h"

// Number of frame times to be counted towards the FPS calculation
#define NUM_FRAMES_AVGD 100
// Times per second to change the FPS shown
#define FPS_RENDER_RATE 10

// For holding delta times for each frame
float frame_times[NUM_FRAMES_AVGD] = { 0 };
// For counting time between updating FPS shown on screen (see FPS_RENDER_RATE above)
unsigned int last_ticks = 0;
// Time deltas to be used in FPS calculation
unsigned int now_time;
unsigned int last_time;
int current_frame = 0;
int fps = 0;

void render_entities() {
    draw_block((struct block*) linked_list_get_item(blocks, 0));
    draw_block((struct block*) linked_list_get_item(blocks, 1));
}

void clear_screen() {
    // Clear the screen with a white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void render_fps() {

    // Calculate delta times
    last_time = now_time;
    now_time = SDL_GetPerformanceCounter();
    float delta = (now_time - last_time)*1000 / (float)SDL_GetPerformanceFrequency();
    frame_times[current_frame++] = delta;
    if(current_frame == NUM_FRAMES_AVGD) {
        current_frame = 0;
    }

    if(SDL_GetTicks() - last_ticks > 1000 / FPS_RENDER_RATE) {
        last_ticks = SDL_GetTicks();
        float total_time = 0;
        for(int i = 0; i < NUM_FRAMES_AVGD; i++) {
            total_time += frame_times[i];
        }
        fps = NUM_FRAMES_AVGD / (total_time / 1000.0f);
    }

    // Texture to hold the drawn text
    SDL_Texture *text_texture = NULL;
    int text_width;
    int text_height;
    SDL_Color color = {0, 0, 0, 255};

    char text[15];
    sprintf(text, "%d", fps);

    load_font_texture(&text_texture, font_open_sans, text, color, &text_width, &text_height);

    SDL_Rect dst = {
        WIDTH/2 - text_width/2,
        HEIGHT/2 - text_height/2,
        text_width,
        text_height
    };

    SDL_RenderCopy(renderer, text_texture, NULL, &dst);
}