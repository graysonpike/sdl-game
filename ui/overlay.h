#ifndef OVERLAY_H
#define OVERLAY_H

#include "../graphics/graphics.h"

class FontRenderer;

class Overlay {

	SDL_Renderer *renderer;

public:

	Overlay(SDL_Renderer *renderer);
	void render_fps(FontRenderer *font_renderer, int fps);

};

#endif