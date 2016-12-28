// Grayson Pike, 2016

#ifndef BLOCK_H
#define BLOCK_H

struct block {
    float x;
    float y;
    int w;
    int h;
};

// Allocates memory for a new block struct, returns pointer.
// Make sure to free() this pointer!
struct block *create_block(double x, double y, int w, int h);

// Draw black rect to renderer
void draw_block(struct block *b);

// Move a block in a given direction. Distance travelled is
// determined by the block's speed and the time delta.
// Params:
// dir can be 'u', 'd', 'l', or 'r' (four directions)
// delta is measured in seconds
void move_block(struct block *b, char dir, double delta);

#endif