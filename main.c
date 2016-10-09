// Grayson Pike, 2016

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graphics/sdl_boilerplate.h"
#include "game/block.h"
#include "data_structure/linked_list.h"

int main() {

    struct node *blocks = linked_list_create();
    linked_list_add_item(blocks, create_block(WIDTH/2, HEIGHT/2, 64, 64));
    linked_list_add_item(blocks, create_block(WIDTH/3, HEIGHT/3, 64, 64));

    graphics_init();

    bool loop = true;
    unsigned int now_time = SDL_GetPerformanceCounter();
    unsigned int last_time = now_time;

    while(loop) {

        SDL_Event event;

        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                loop = false;
            }
            if(event.type == SDL_KEYDOWN) {
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        loop = false;
                        break;
                    default:
                        break;
                }
            }
        }

        // Calculate delta times
        last_time = now_time;
        now_time = SDL_GetPerformanceCounter();
        double delta = (now_time - last_time)*1000 / (double)SDL_GetPerformanceFrequency();

        // Key states
        const Uint8 *key_states = SDL_GetKeyboardState(NULL);
        struct block *b = (struct block*)linked_list_get_item(blocks, 0);
        if(key_states[SDL_SCANCODE_UP]) {
            move_block(b, 'u', delta);
        }
        if(key_states[SDL_SCANCODE_DOWN]) {
            move_block(b, 'd', delta);
        }
        if(key_states[SDL_SCANCODE_LEFT]) {
            move_block(b, 'l', delta);
        }
        if(key_states[SDL_SCANCODE_RIGHT]) {
            move_block(b, 'r', delta);
        }
        

        // Render entities
        clear_screen();
        draw_block((struct block*) linked_list_get_item(blocks, 0));
        draw_block((struct block*) linked_list_get_item(blocks, 1));
        SDL_RenderPresent(renderer);

    }

    graphics_quit();

    linked_list_free_list(blocks);

    return 0;
}