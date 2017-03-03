#include <SDL2/SDL.h>
#include "world.h"
#include "../entities/player.h"

World::World() {
	entities.push_back(new Player(64, 64));
}

// Main cycle running game logic (inputs, physics, mechanics, etc.)
void World::update(Inputs *inputs) {

    // Reset delta since last cycle
    clock.tick();

    // EVENTS
    

    // TODO: Update entities
}

float World::get_delta() {
	return clock.get_delta();
}

std::vector<Entity*> *World::get_entities() {
	return &entities;
}