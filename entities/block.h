// Grayson Pike, 2016

#ifndef BLOCK_H
#define BLOCK_H

#include <stdbool.h>

// Velocity lost in collision with a wall. 1.0f = perfectly elastic
#define WALL_FRICTION (1.0f)

// x, y are the coordinate positions of the block on the screen
// w, h define the width and height of the block
// vx, vy are the velocity vectors of the block
// ax, ay are the acceleration vectors of the block
// the moved flag is used when applying friction with the ground
//     (friction is only applied when not moving by keypresses)
struct block {
    float x;
    float y;
    int w;
    int h;
    float vx;
    float vy;
    double angle;
};

// Allocates memory for a new block struct, returns pointer.
// Make sure to free() this pointer!
struct block *create_block(double x, double y, int w, int h, double angle);

// Draw black rect to renderer
void draw_block(struct block *b);

// Instantaneously accelerate a block in a given direction
// Best for effects like explosions and knockback
void accel_block(struct block *b, float x, float y);

// Move a block at a given speed in the x and y directions
// Clamps to screen edges
void move_block(struct block *b, float x, float y, float delta);

// Update physics on a block for this game cycle
// Changes velocity by acceleration and clamps to screen edges
void update_block(struct block *b, float delta);

#endif