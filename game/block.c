// Grayson Pike, 2016

#include <stdlib.h>
#include "block.h"

struct block *create_block(int x, int y, int w, int h) {
	struct block *b = malloc(sizeof(struct block));
	b->x = x;
	b->y = y;
	b->w = w;
	b->h = h;
	return b;
}

void draw_block(struct block *b) {
	
}