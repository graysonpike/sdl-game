// Grayson Pike, 2016

#ifndef BLOCK_H
#define BLOCK_H

struct block {
    int x;
    int y;
    int w;
    int h;
};

struct block *create_block(int x, int y, int w, int h);
void draw_block(struct block *b);

#endif