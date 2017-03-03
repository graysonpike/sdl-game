#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <list>
#include "clock.h"
#include "entity.h"
#include "../input/inputs.h"

class World {
	
	Clock clock;
	std::list<Entity> entities;

public:
	void update(Inputs *inputs);
	float get_delta();
	std::list<Entity> *get_entities();

};

#endif