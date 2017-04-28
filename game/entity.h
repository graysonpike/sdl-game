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
	int w, h;
	int screen_w, screen_h;
	Hitbox *hitbox;

	float get_center_x();
	float get_center_y();
	void check_bounds();

public:

	Entity(float x, float y, int w, int h, int screen_w, int screen_h);
	Hitbox *get_hitbox();
	float get_x();
	float get_y();
	virtual ~Entity() = 0;
	virtual void update(float delta) = 0;
	virtual void render(SDL_Renderer *renderer, Resources *resources, float delta) = 0;
	virtual bool is_alive() = 0;
	virtual const int get_id() = 0;
	virtual const bool collides() = 0;
	virtual bool does_collide(int id) = 0;
	virtual void collide_entity(Entity *entity) = 0;

};

#endif