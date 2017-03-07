#ifndef OVERLAY_H
#define OVERLAY_H

#include "../graphics/graphics.h"

class Overlay {

public:
	void render_fps(SDL_Renderer *renderer, int fps);

};

#endif