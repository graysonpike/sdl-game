#include "player.h"

const int Player::w = 64;
const int Player::h = 64;
const std::string Player::texture_name = "player";

Player::Player(float x, float y) : Entity(x, y) {
	hitbox = new Hitbox(x, y, w, h);
}

std::string Player::get_texture_name() {
	return texture_name;
}

Player::~Player() {
	delete hitbox;
}

void Player::update(float delta) {
	return;
}

void Player::render(float delta) {
	return;
}