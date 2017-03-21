#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include "hitbox.h"
#include "world.h"
#include "../graphics/resources.h"

class World;

class Entity {

protected:
	
	float x, y;
	Hitbox *hitbox;

public:
	Entity(float x, float y);
	Hitbox *get_hitbox();
	float get_x();
	float get_y();
	void move_offset(float x, float y);

	virtual ~Entity() = 0;
	virtual void update(float delta) = 0;
	virtual void render(SDL_Renderer *renderer, Resources *resources, float delta) = 0;
};

#endif