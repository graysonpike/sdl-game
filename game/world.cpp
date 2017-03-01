#include <SDL2/SDL.h>
#include "world.h"

Clock World::clock;

// Main cycle running game logic (inputs, physics, mechanics, etc.)
void World::update(Inputs *inputs) {

    // Reset delta since last cycle
    clock.tick();

    // EVENTS
    

    // TODO: Update entities
}