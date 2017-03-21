#ifndef PLAYER_H
#define PLAYER_H

#include "../game/entity.h"
#include "../game/hitbox.h"
#include "../input/inputs.h"
#include <string>

class Player: public Entity {

    static const int w, h;
	// Speed in px/sec
	float vx, vy;
	float turn_speed, linear_accel;
	float max_speed;
	int player_num;
	float angle;
	int screen_w, screen_h;

	float get_center_x();
	float get_center_y();

public:
	Player(float x, float y, int player_num, int screen_w, int screen_h);
	void update(float delta);
	void render(SDL_Renderer *renderer, Resources *resources, float delta);
	void handle_inputs(float delta, Inputs *inputs);
};

#endif