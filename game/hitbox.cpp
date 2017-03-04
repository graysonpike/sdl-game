#include "hitbox.h"

Hitbox::Hitbox(float x, float y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Hitbox::update_pos(float x, float y) {
	this->x = x + x_offset;
	this->y = y + y_offset;
}