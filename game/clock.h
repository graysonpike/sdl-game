#ifndef CLOCK_H
#define CLOCK_H

// Keeps track of 'delta' times between frames
class Clock {

	unsigned int last_time;
	float delta;

public:

	// The first delta begins as soon as the clock is created
	Clock();
	// Sets last_time to SDL_GetTicks()
	void reset();
	// Returns the delta time in seconds between the last two calls to tick()
	float get_delta();
	// Recalculates then resets the delta
	void tick();
	
};

#endif