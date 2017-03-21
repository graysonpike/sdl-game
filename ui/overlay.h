#ifndef OVERLAY_H
#define OVERLAY_H

#include "../graphics/graphics.h"

class FontRenderer;

class Overlay {

	int width, height;
	SDL_Renderer *renderer;
	Resources *resources;

public:

	Overlay(int width, int height, SDL_Renderer *renderer, Resources *resources);
	void render_fps(FontRenderer *font_renderer, int fps);

};

#endif