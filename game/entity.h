#ifndef ENTITY_H
#define ENTITY_H

#include "hitbox.h"
#include <string>

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
	virtual void render(float delta) = 0;
	virtual std::string get_texture_name() = 0;
};

#endif