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
    b->ax = 0;
    b->ay = 0;
    b->moved = false;
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

void accel_block(struct block *b, float mag, char dir) {
    switch(dir) {
        case 'u':
            b->ay -= mag;
            break;
        case 'd':
            b->ay += mag;
            break;
        case 'l':
            b->ax -= mag;
            break;
        case 'r':
            b->ax += mag;
            break;
        default:
            printf("ERROR: move_block(): Received invalid direction char.\n");
            break;
    }
}

void update_block(struct block *b, float delta) {

    // GROUND FRICTION
    // Only apply ground friction with the ground if
    // not currently moving (by keypress)
    if(!b->moved) {
        // Apply friction to velocity as a deceleration
        if(b->vx > 0) {
            accel_block(b, BLOCK_FRICTION * FRICTION, 'l');
        } else if(b->vx < 0) {
            accel_block(b, BLOCK_FRICTION * FRICTION, 'r');
        }
        if(b->vy > 0) {
            accel_block(b, BLOCK_FRICTION * FRICTION, 'u');
        } else if(b->vy < 0) {
            accel_block(b, BLOCK_FRICTION * FRICTION, 'd');
        }
    }
    // Reset moved flag for next game cycle
    b->moved = false;

    // ACCELERATION & VELOCITY
    // Apply current acceleration
    b->vx += (b->ax * delta);
    b->vy += (b->ay * delta);
    // Apply current velocity
    b->x += (b->vx * delta);
    b->y += (b->vy * delta);
    // Reset acceleration for next game cycle
    b->ax = 0;
    b->ay = 0;

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