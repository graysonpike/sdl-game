#ifndef WORLD_H
#define WORLD_H

#include <stdbool.h>
#include <vector>
#include "clock.h"
#include "entity.h"
#include "collision_manager.h"
#include "../input/inputs.h"

#define NUM_PLAYERS 2

class Entity;
class CollisionManager;

class World {
	
    static const float respawn_delay;
    int screen_w, screen_h;
	Clock clock;
	CollisionManager *collision_manager;
	std::vector<Entity*> entities;
    float player_respawn_timers[NUM_PLAYERS];

    void check_spawn_players();

public:

	World(int screen_w, int screen_h);
	void update(Inputs *inputs);
	float get_delta();
	std::vector<Entity*> *get_entities();
	~World();
    
};

#endif