#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <vector>
#include "clock.h"
#include "entity.h"
#include "../input/inputs.h"

class Entity;

class World {
	
	Clock clock;
	std::vector<Entity*> entities;

public:
	World();
	void update(Inputs *inputs);
	float get_delta();
	std::vector<Entity*> *get_entities();
	~World();
};

#endif