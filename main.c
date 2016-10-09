// Grayson Pike, 2016

#include <stdio.h>
#include <stdlib.h>
#include "graphics/sdl_boilerplate.h"
#include "game/block.h"
#include "data_structure/linked_list.h"

int main() {

    struct node *blocks = linked_list_create();
    linked_list_add_item(blocks, create_block(WIDTH/2, HEIGHT/2, 64, 64));
    linked_list_add_item(blocks, create_block(WIDTH/3, HEIGHT/3, 64, 64));
    linked_list_add_item(blocks, create_block(WIDTH/4, HEIGHT/4, 64, 64));

    printf("%d\n", ((struct block*)linked_list_get_item(blocks, 0))->x);
    printf("%d\n", ((struct block*)linked_list_get_item(blocks, 1))->x);
    printf("%d\n", ((struct block*)linked_list_get_item(blocks, 2))->x);

    /*
    graphics_init();

    clear_screen();
    draw_block(b);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    graphics_quit();
    */

    linked_list_free_list(blocks);

    return 0;
}