// Grayson Pike, 2016

#include <stdio.h>
#include <stdlib.h>
#include "graphics/sdl_boilerplate.h"
#include "game/block.h"

int main() {

    graphics_init();

    struct block *b = create_block(WIDTH/2, HEIGHT/2, 64, 64);
    printf("%d, %d\n", b->x, b->y);
    free(b);

    graphics_quit();

    return 0;
}