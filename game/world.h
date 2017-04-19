#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <vector>
#include "clock.h"
#include "entity.h"
#include "collision_manager.h"
#include "../input/inputs.h"

class Entity;
class CollisionManager;

class World {
	
    int screen_w, screen_h;
	Clock clock;
	CollisionManager *collision_manager;
	std::vector<Entity*> entities;

    void check_spawn_players();

public:

	World(int screen_w, int screen_h);
	void update(Inputs *inputs);
	float get_delta();
	std::vector<Entity*> *get_entities();
	~World();
    
};

#endif