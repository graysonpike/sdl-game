#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include "hitbox.h"
#include "entity.h"

class CollisionManager {

public:
	void check_collisions(std::vector<Entity *> *entities);

};


#endif