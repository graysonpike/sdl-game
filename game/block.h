// Grayson Pike, 2016

#ifndef BLOCK_H
#define BLOCK_H

struct block {
    float x;
    float y;
    int w;
    int h;
};

struct block *create_block(double x, double y, int w, int h);
void draw_block(struct block *b);
void move_block(struct block *b, char dir, double delta);

#endif