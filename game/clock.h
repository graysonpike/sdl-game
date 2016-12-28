#ifndef CLOCK_H
#define CLOCK_H

unsigned int last_time;
unsigned int current_time;

// To be called upon initializing the game, sets
// last_time and current_time to SDL_GetTicks()
void init_clock();
// Returns the delta time in seconds since the last
// time get_delta was called.
float get_delta();

#endif