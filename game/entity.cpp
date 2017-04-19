#include "entity.h"

Entity::Entity(float x, float y) {

	this->x = x;
	this->y = y;
    this->hitbox = NULL;

}

Hitbox* Entity::get_hitbox() {
    return hitbox;
}

float Entity::get_x() {
	return x;
}

float Entity::get_y() {
	return y;
}

Entity::~Entity() {

    if(hitbox != NULL) {
        delete hitbox;
    }

}
