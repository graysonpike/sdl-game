#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "resources.h"


class Graphics {

	static const int WIDTH, HEIGHT;
	int fps;
	Resources resources;
	SDL_Window *window;
	SDL_Renderer *renderer;


	bool init_sdl();
	bool load_font_texture(SDL_Texture **texture, std::string font, std::string text, SDL_Color text_color);

public:
	Graphics();
	void render_fps();
	void clear_screen();
	void present_renderer();
	~Graphics();
};

#endif