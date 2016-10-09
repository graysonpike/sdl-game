// Grayson Pike, 2016

#include <stdlib.h>
#include "block.h"
#include "../graphics/sdl_boilerplate.h"

// extern from sdl_boilerplate.h
SDL_Renderer *renderer;

struct block *create_block(int x, int y, int w, int h) {
	struct block *b = malloc(sizeof(struct block));
	b->x = x;
	b->y = y;
	b->w = w;
	b->h = h;
	return b;
}

void draw_block(struct block *b) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
	SDL_Rect bar = {
        b->x,
        b->y,
        b->w,
        b->h
    };
    SDL_RenderFillRect(renderer, &bar);
}