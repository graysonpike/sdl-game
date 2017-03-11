#include "player.h"

const int Player::w = 32;
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

void Player::render(SDL_Renderer *renderer, Resources *resources, float delta) {

	// BODY
	// To create a jiggly walking motion, oscillating sine function is used
	// as a modifier to the width
	float width_modifier = sin(SDL_GetTicks() / 80.0f);
	int width_change = 0 * (int) 2 * width_modifier;
	SDL_Rect body = {
		(int)x - width_change,
		(int)y,
		w + (width_change * 2),
		h
	};
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &body);

	// EYES
	SDL_Rect left_eye = {
		(int) x + 6,
		(int) y + 10,
		5,
		15
	};
	SDL_Rect right_eye = {
		(int) x + w - 5 - 6,
		(int) y + 10,
		5,
		15
	};
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &left_eye);
	SDL_RenderFillRect(renderer, &right_eye);
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