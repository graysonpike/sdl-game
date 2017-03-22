#ifndef PLAYER_H
#define PLAYER_H

#include "../game/entity.h"
#include "../game/hitbox.h"
#include "../input/inputs.h"
#include <string>

class Player: public Entity {

	// References
	std::vector<Entity*> *entities;
	int screen_w, screen_h;

	// General Variables
    static const int w, h;
	float vx, vy;
	float turn_speed, linear_accel;
	float max_speed;
	int player_num;
	float angle;
	float missile_cooldown;

	// Helper Functions
	float get_center_x();
	float get_center_y();

public:
	Player(float x, float y, int player_num, int screen_w, int screen_h, std::vector<Entity*> *entities);
	void update(float delta);
	void render(SDL_Renderer *renderer, Resources *resources, float delta);
	void handle_inputs(float delta, Inputs *inputs);
	bool is_alive();
};

#endif