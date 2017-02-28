#ifndef RESOURCES_H
#define RESOURCES_H

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Resources {

	std::map<std::string, TTF_Font*> fonts;

public:
	

};

void load_resources();

#endif