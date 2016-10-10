// Grayson Pike, 2016

#include "render.h"
#include "sdl_boilerplate.h"
#include "../game/game.h"
#include "../game/block.h"
#include "../data_structure/linked_list.h"

void render_entities() {
    clear_screen();
    draw_block((struct block*) linked_list_get_item(blocks, 0));
    draw_block((struct block*) linked_list_get_item(blocks, 1));
    SDL_RenderPresent(renderer);
}

void clear_screen() {
    // Clear the screen with a white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}
