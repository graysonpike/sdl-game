#include "hitbox.h"

Hitbox::Hitbox(float x, float y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Hitbox::set_pos(float x, float y) {
	this->x = x;
	this->y = y;
}