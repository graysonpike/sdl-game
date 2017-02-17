#include "resources.h"
#include "sdl_boilerplate.h"

std::map<std::string, TTF_Font*> fonts;

void load_resources() {

	// FONTS
	fonts["inconsolata"] = NULL;
    load_font(&fonts["inconsolata"], "Inconsolata/Inconsolata-Regular.ttf", 18);
}