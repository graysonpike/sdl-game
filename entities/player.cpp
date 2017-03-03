#include "player.h"

Player::Player(float x, float y) {
	this->x = x;
	this->y = y;
	hitbox = new Hitbox(x, y, 64, 64);
}

Player::~Player() {
	delete hitbox;
}