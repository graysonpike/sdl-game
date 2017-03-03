#ifndef ENTITY_H
#define ENTITY_H

#include "hitbox.h"

class Entity {

protected:
	int x, y;
	Hitbox *hitbox;

public:
	Entity();
	virtual void update(float delta);
	virtual void render(float delta);
	virtual Hitbox get_hitbox();
};

#endif