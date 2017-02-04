#ifndef CHARACTER_H
#define CHARACTER_H

#include "block.h"

struct character {
    int health;
    struct block *block;
};

struct character *create_character(float x, float y);
void destroy_character(struct character *c);
void draw_character(struct character *c);

#endif