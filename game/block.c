// Grayson Pike, 2016

#include <stdlib.h>
#include "block.h"
#include "../graphics/sdl_boilerplate.h"

// Block speed in pixels per second
#define BLOCK_SPEED 300l

// extern from sdl_boilerplate.h
SDL_Renderer *renderer;

struct block *create_block(double x, double y, int w, int h) {
	struct block *b = malloc(sizeof(struct block));
	b->x = x;
	b->y = y;
	b->w = w;
	b->h = h;
    printf("%f\n", b->x);
	return b;
}

void draw_block(struct block *b) {
    // All blocks are black and opaque so far
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
	SDL_Rect rect = {
        (int)b->x,
        (int)b->y,
        b->w,
        b->h
    };
    SDL_RenderFillRect(renderer, &rect);
}

void move_block(struct block *b, char dir, double delta) {
    switch(dir) {
        case 'u':
            b->y -= BLOCK_SPEED * delta;
            break;
        case 'd':
            b->y += BLOCK_SPEED * delta;
            break;
        case 'l':
            b->x -= BLOCK_SPEED * delta;
            break;
        case 'r':
            b->x += BLOCK_SPEED * delta;
            break;
        default:
            printf("ERROR: move_block(): Received invalid direction char.\n");
            break;
    }
}