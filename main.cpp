#include <stdlib.h>
#include <time.h>
#include "graphics/graphics.h"
#include "game/world.h"
#include "input/inputs.h"

int main() {

    // Initialize random seed
    srand(time(NULL));

    Inputs inputs;
    Graphics graphics;
    World world(graphics.get_width(), graphics.get_height());

    bool loop = true;

    while(loop) {

        inputs.update();
        loop = !inputs.get_quit();

    	world.update(&inputs);
        
        graphics.clear_screen();
        graphics.render_entities(world.get_entities(), world.get_delta());
        graphics.render_overlay(world.get_entities());

        graphics.present_renderer(world.get_delta());
        
    }

    return 0;
}

