#include "resources.h"
#include "graphics.h"

void Resources::load_resources() {

	// FONTS
	fonts["inconsolata"] = NULL;
    load_font(&fonts["inconsolata"], "Inconsolata/Inconsolata-Regular.ttf", 18);
}