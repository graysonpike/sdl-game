#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "../graphics/sdl_boilerplate.h"
#include "../data_structure/linked_list.h"

// Fraction of velocity retained after 1 second
#define FRICTION (0.05f)

struct character *player_char;

void game_init();
bool game_update();
void game_quit();

#endif