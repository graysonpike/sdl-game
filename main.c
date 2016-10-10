// Grayson Pike, 2016

#include <stdio.h>
#include <stdbool.h>
#include "graphics/sdl_boilerplate.h"
#include "graphics/render.h"
#include "game/game.h"

int main() {

    graphics_init();
    game_init();

    bool loop = true;

    while(loop) {
        loop = game_update();
        clear_screen();
        render_entities();
    }

    graphics_quit();
    game_quit();

    return 0;
}