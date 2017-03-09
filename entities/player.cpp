#include "player.h"

const int Player::w = 64;
const int Player::h = 64;
const std::string Player::texture_name = "player";

Player::Player(float x, float y) : Entity(x, y) {
	hitbox = new Hitbox(x, y, w, h);
	speed = 200;
	health = 3;
	max_health = 5;
}

std::string Player::get_texture_name() {
	return texture_name;
}

void Player::update(float delta) {
	return;
}

void Player::handle_inputs(float delta, Inputs *inputs) {
	float distance = speed * delta;
	if(inputs->is_key_down(KEY_MOVE_UP)) {
		move_offset(0, -distance);
	} else if (inputs->is_key_down(KEY_MOVE_DOWN)) {
		move_offset(0, distance);
	}
	if(inputs->is_key_down(KEY_MOVE_LEFT)) {
		move_offset(-distance, 0);
	} else if (inputs->is_key_down(KEY_MOVE_RIGHT)) {
		move_offset(distance, 0);
	}
}

int Player::get_health() {
	return health;
}

int Player::get_max_health() {
	return max_health;
}