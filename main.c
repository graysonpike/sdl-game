// Grayson Pike, 2016

#include <stdio.h>
#include <stdbool.h>
#include "graphics/sdl_boilerplate.h"
#include "graphics/render.h"
#include "graphics/resources.h"
#include "game/game.h"

int main() {

    graphics_init();
    load_images();
    game_init();

    bool loop = true;

    while(loop) {

        loop = game_update();
        clear_screen();
        render_entities();
        render_fps();

        SDL_RenderPresent(renderer);
        
    }

    graphics_quit();
    game_quit();

    return 0;
}