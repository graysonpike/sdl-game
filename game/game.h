#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

// Fraction of velocity retained after 1 second
//#define FRICTION (0.05f)

void game_init();
bool game_update();
void game_quit();

#endif