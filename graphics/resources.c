#include "resources.h"
#include "sdl_boilerplate.h"

SDL_Texture *character_texture;

void load_images() {
    load_texture(&character_texture, "player.png");
}