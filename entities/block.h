// Grayson Pike, 2016

#ifndef BLOCK_H
#define BLOCK_H

#include <stdbool.h>

#define BLOCK_ACCEL (300.0f)
#define BLOCK_FRICTION (300.0f)
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
    float ax;
    float ay;
    bool moved;
};

// Allocates memory for a new block struct, returns pointer.
// Make sure to free() this pointer!
struct block *create_block(double x, double y, int w, int h);

// Draw black rect to renderer
void draw_block(struct block *b);

// Accelerate a block in a given direction. Distance travelled is
// determined by the block's speed and the time delta.
// Params:
// mag -> magnitude of accel in px/s^2
// dir can be 'u', 'd', 'l', or 'r' (four directions)
// delta is measured in seconds
void accel_block(struct block *b, float mag, char dir);

// Update physics on a block for this game cycle
// Changes velocity by acceleration and clamps to screen edges
void update_block(struct block *b, float delta);

#endif