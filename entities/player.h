#ifndef PLAYER_H
#define PLAYER_H

#include "../game/entity.h"
#include "../game/hitbox.h"
#include "../input/inputs.h"
#include <string>

class Player: public Entity {

    static const int w, h;
    static const std::string texture_name;
	// Speed in px/sec
	float speed;
	int health, max_health;

public:
	Player(float x, float y);
	void update(float delta);
	// void render(float delta);
	std::string get_texture_name();
	void handle_inputs(float delta, Inputs *inputs);
	int get_health();
	int get_max_health();
};

#endif