#include "resources.h"
#include "graphics.h"

#include <iostream>

const std::string Resources::RES_DIR = "res/";

Resources::Resources(SDL_Renderer *renderer) {
	this->renderer = renderer;
}

void Resources::load_resources() {

	// FONTS
	fonts["inconsolata"] = NULL;
    load_font(&fonts["inconsolata"], "Inconsolata/Inconsolata-Regular.ttf", 18);

    // TEXTURES
    load_texture(&textures["ship1"][1], "ship1.png");
    load_texture(&textures["ship2"][1], "ship2.png");
    load_texture(&textures["missile1"][1], "missile1.png");
    load_texture(&textures["missile2"][1], "missile2.png");
    load_texture(&textures["explosion"][1], "explosion1.png");
    load_texture(&textures["explosion"][2], "explosion2.png");
    load_texture(&textures["explosion"][3], "explosion3.png");
    load_texture(&textures["explosion"][4], "explosion4.png");
    load_texture(&textures["explosion"][5], "explosion5.png");
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

TTF_Font* Resources::get_font(std::string name) {
	return fonts[name];
}

SDL_Texture* Resources::get_texture(std::string name, int frame) {
    return textures[name][frame];
}

Resources::~Resources() {
    // Iterate through fonts and free them
    std::map<std::string, TTF_Font*>::iterator font_it;
    for(font_it = fonts.begin(); font_it != fonts.end(); font_it++) {
        TTF_CloseFont(font_it->second);
    }
    
    // Iterate through textures and free them
    std::map<std::string, std::map<int, SDL_Texture*> >::iterator frames;
    for(frames = textures.begin(); frames != textures.end(); frames++) {
        std::map<int, SDL_Texture*>::iterator frame;
        for(frame = frames->second.begin(); frame != frames->second.end(); frame++) {
            //SDL_DestroyTexture(frame->second);
            frame->second = NULL;
        }
    }
    
}