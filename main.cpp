#include "graphics/sdl_boilerplate.h"
#include "game/world.h"
#include "input/inputs.h"

int main() {

    Inputs inputs;
    World world;

    graphics_init();
    //load_images();
    game_init();

    bool loop = true;

    while(loop) {

        inputs.update();
    	world.update(&inputs);
        
        clear_screen();
        render_fps();

        SDL_RenderPresent(renderer);
        
    }

    graphics_quit();
    game_quit();

    return 0;
}

