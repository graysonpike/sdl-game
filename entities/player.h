#ifndef PLAYER_H
#define PLAYER_H

#include "../game/entity.h"

class Player: public Entity{
public:
	Player(float x, float y);
	~Player();
};

#endif