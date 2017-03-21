#include <SDL2/SDL.h>
#include "world.h"
#include "../entities/player.h"

World::World(int screen_w, int screen_h) {
	entities.push_back(new Player(64, 64, 1, screen_w, screen_h));
}

// Main cycle running game logic (inputs, physics, mechanics, etc.)
void World::update(Inputs *inputs) {

    // Reset delta since last cycle
    clock.tick();

    // INPUT HANDLING
    // Player is always index 0
    ((Player*)entities[0])->handle_inputs(clock.get_delta(), inputs);

    // ENTITIES
    for(int i = 0; i < entities.size(); i++) { 
    	entities[i]->update(clock.get_delta());
    }
}

float World::get_delta() {
	return clock.get_delta();
}

std::vector<Entity*> *World::get_entities() {
	return &entities;
}

World::~World() {
	// Free all entities
	for(int i = 0; i < entities.size(); i++) { 
    	delete entities[i];
    }
}