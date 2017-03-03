#ifndef PLAYER_H
#define PLAYER_H

#include "../game/entity.h"
#include "../game/hitbox.h"
#include <string>

class Player: public Entity{

	static const int w, h;
	static const std::string texture_name;

public:
	Player(float x, float y);
	void update(float delta);
	void render(float delta);
	std::string get_texture_name();
	~Player();
};

#endif