#include <SDL2/SDL.h>
#include "world.h"
#include "../entities/player.h"

World::World(int screen_w, int screen_h) {

    collision_manager = new CollisionManager(&entities);
	entities.push_back(new Player(64, 64, 1, screen_w, screen_h, &entities));
    entities.push_back(new Player(128, 128, 2, screen_w, screen_h, &entities));

}

// Main cycle running game logic (inputs, physics, mechanics, etc.)
void World::update(Inputs *inputs) {

    // Reset delta since last cycle
    clock.tick();

    // Handle input
    // Deliver input to each Player
    for(int i = 0; i < entities.size(); i++) {
        if(entities[i]->get_id() == 0) {
            ((Player*)entities[i])->handle_inputs(clock.get_delta(), inputs);
        }
    }

    // Update entities
    for(int i = 0; i < entities.size(); i++) { 
    	entities[i]->update(clock.get_delta());
    }

    // Check for collisions
    collision_manager->check_collisions();

    // Prune dead entities from entites vector
    for(int i = 0; i < entities.size(); i++) {
        if(!entities[i]->is_alive()) {
            delete entities[i];
            entities[i] = NULL;
            entities.erase(entities.begin() + i);
            i -= 1;
        }
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
        entities[i] = NULL;
    }

    // Free collision manager
    delete collision_manager;
    collision_manager = NULL;
    
}