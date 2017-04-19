#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "resources.h"
#include "fps_counter.h"
#include "../game/entity.h"
#include "font_renderer.h"
#include "../ui/overlay.h"

class Overlay;
class FontRenderer;

class Graphics {

	// Width and heigh of the window in px
	static const int WIDTH, HEIGHT;

	Resources *resources;
	FPSCounter fps_counter;
	FontRenderer *font_renderer;
	Overlay *overlay;
	SDL_Window *window;
	SDL_Renderer *renderer;

	bool init_sdl();

public:
	Graphics();
	void clear_screen();
	void render_overlay(std::vector<Entity*> *entities);
	void present_renderer(float delta);
	void render_entities(std::vector<Entity*> *entities, float delta);
	int get_width();
	int get_height();
	~Graphics();
};

#endif