#include "entity.h"

// PRIVATE HELPER METHODS

float Entity::get_center_x() {
    return x + w/2;
}

float Entity::get_center_y() {
    return y + h/2;
}

void Entity::check_bounds() {

	if(this->get_center_x() < 0) {
	    x = screen_w - w/2;
	} else if (this->get_center_x() > screen_w) {
	    x = 0 - w/2;
	}
	if(this->get_center_y() < 0) {
	    y = screen_h - h/2;
	} else if (this->get_center_y() > screen_h) {
	    y = 0 - h/2;
	}

}

// PUBLIC METHODS

Entity::Entity(float x, float y, int w, int h, int screen_w, int screen_h) {

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
    this->hitbox = NULL;
    this->screen_w = screen_w;
    this->screen_h = screen_h;

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
