#ifndef HITBOX_H
#define HITBOX_H

class Hitbox {
	float x, y;
	int x_offset, y_offset, w, h;

public:
	Hitbox(float x_offset, float y_offset, int w, int h);
	void update_pos(float x, float y);
};

#endif