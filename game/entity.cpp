#include "entity.h"

Entity::Entity(float x, float y) {
	this->x = x;
	this->y = y;
}

float Entity::get_x() {
	return x;
}

float Entity::get_y() {
	return y;
}

Hitbox* Entity::get_hitbox() {
	return hitbox;
}

void Entity::move_offset(float x, float y) {
	this->x += x;
	this->y += y;
}

Entity::~Entity() {
	delete hitbox;
}
