#include <iostream>
#include "graphics/sdl_boilerplate.h"
#include "game/game.h"
#include "graphics/render.h"

int main() {

    graphics_init();
    //load_images();
    game_init();

    bool loop = true;

    while(loop) {

    	// GAME LOOP
        loop = game_update();

        clear_screen();
        render_fps();

        SDL_RenderPresent(renderer);
        
    }

    graphics_quit();
    game_quit();

    return 0;
}

