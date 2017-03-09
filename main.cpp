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
        loop = !inputs.get_quit();

    	world.update(&inputs);
        
        graphics.clear_screen();
        graphics.render_entities(world.get_entities(), world.get_delta());
        graphics.render_overlay(world.get_entities());

        graphics.present_renderer(world.get_delta());
        
    }

    return 0;
}

