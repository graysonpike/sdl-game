#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include "entity.h"

class Entity;

class CollisionManager {

	std::vector<Entity*> *entities;

public:

	CollisionManager(std::vector<Entity*> *entites);
	void check_collisions();
    
};

#endif