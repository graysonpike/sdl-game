#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "clock.h"
#include "../input/inputs.h"

class World {
	
	Clock clock;

public:
	void update(Inputs *inputs);

};

#endif