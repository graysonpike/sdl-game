#include "resources.h"
#include "graphics.h"

const std::string Resources::RES_DIR = "res/";

Resources::Resources(SDL_Renderer *renderer) {
	this->renderer = renderer;
}

void Resources::load_resources() {

	// FONTS
	fonts["inconsolata"] = NULL;
    load_font(&fonts["inconsolata"], "Inconsolata/Inconsolata-Regular.ttf", 18);

    // TEXTURES
}

bool Resources::load_texture(SDL_Texture **texture, std::string filename){
    // Assumes texture is not already created
    *texture = NULL;
    // Imagefile -> Surface -> Texture
    // Empty surface to begin with
    SDL_Surface *loaded_surface = NULL;
    // Concatenate filename to resource directory
    std::string filepath = std::string(RES_DIR) + "images/" + filename;
    // Load imagefile into surface
    loaded_surface = IMG_Load(filepath.c_str());
    // Check first to see if the load failed
    if(loaded_surface == NULL) {
        printf("Error loading image: %s\n", SDL_GetError());
        return false;
    }
    // If successful, transfer the surface into the texture
    *texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if(texture == NULL) {
        printf("Unable to create texture from surface: %s\n", SDL_GetError());
    }
    // Free the temporary surface
    SDL_FreeSurface(loaded_surface);
    return true;
}



bool Resources::load_font(TTF_Font **font, std::string filename, int size) {
    // Concatenate filename to resource directory
    std::string filepath = std::string(RES_DIR) + "fonts/" + filename;
    *font = TTF_OpenFont(filepath.c_str(), size);
    if(*font == NULL) {
        printf("Error loading font: %s\n", TTF_GetError());
        return false;
    }
    return true;
}

TTF_Font* Resources::get_font(std::string font) {
	return fonts[font];
}