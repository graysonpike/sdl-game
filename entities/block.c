// Grayson Pike, 2016

#include <stdlib.h>
#include <math.h>
#include "block.h"
#include "../graphics/sdl_boilerplate.h"
#include "../game/game.h"

// extern from sdl_boilerplate.h
SDL_Renderer *renderer;

struct block *create_block(double x, double y, int w, int h) {
	struct block *b = malloc(sizeof(struct block));
	b->x = x;
	b->y = y;
	b->w = w;
	b->h = h;
    b->vx = 0;
    b->vy = 0;
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

void clamp_block(struct block *b) {
    if(b->x < 0) {
        b->x = 0;
    } else if (b->x > WIDTH - b->w) {
        b->x = WIDTH - b->w;
    }
    if(b->y < 0) {
        b->y = 0;
    } else if (b->y > HEIGHT - b->h) {
        b->y = HEIGHT - b->h;
    }
}

void move_block(struct block *b, float x, float y, float delta) {
    b->x += x * delta;
    b->y += y * delta;
    clamp_block(b);
}

void accel_block(struct block *b, float x, float y) {
    b->vx = x;
    b->vy = y;
}

void update_block(struct block *b, float delta) {

    // ACCELERATION & VELOCITY
    // Apply current velocity
    b->x += (b->vx * delta);
    b->y += (b->vy * delta);
    // Lower velocity due to friction
    b->vx *= FRICTION * delta;
    b->vy *= FRICTION * delta;

    // WALL COLLISION
    // If hitting a wall, bounce off going the opposite direction
    // Change WALL_FRICTION to change the amount of
    // speed lost hitting a wall. 1.0f is perfectly elastic
    if(b->x < 0) {
        b->vx = -(b->vx) * WALL_FRICTION;
        b->x = 0;
    } else if (b->x > WIDTH - b->w) {
        b->vx = -(b->vx) * WALL_FRICTION;
        b->x = WIDTH - b->w;
    }
    if(b->y < 0) {
        b->vy = -(b->vy) * WALL_FRICTION;
        b->y = 0;
    } else if (b->y > HEIGHT - b->h) {
        b->vy = -(b->vy) * WALL_FRICTION;
        b->y = HEIGHT - b->h;
    }
}