#ifndef HITBOX_H
#define HITBOX_H

class Hitbox {
	float x, y;
	int w, h;

public:
	Hitbox(float x, float y, int w, int h);
	void set_pos(float x, float y);
};

#endif