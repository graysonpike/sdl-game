#include "graphics/graphics.h"
#include "game/world.h"
#include "input/inputs.h"

int main() {

    Inputs inputs;
    World world;
    Graphics graphics;

    bool loop = true;

    while(loop) {

        inputs.update();
    	world.update(&inputs);
        
        graphics.clear_screen();
        graphics.render_fps();

        graphics.present_renderer();
        
    }

    return 0;
}

