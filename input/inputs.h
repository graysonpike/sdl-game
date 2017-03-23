#ifndef INPUTS_H
#define INPUTS_H

#include <SDL2/SDL.h>

// KEY CODE DEFINITIONS
// Edit this file to change key bindings

#define KEY_P1_MOVE_UP SDL_SCANCODE_W
#define KEY_P1_MOVE_DOWN SDL_SCANCODE_S
#define KEY_P1_MOVE_LEFT SDL_SCANCODE_A
#define KEY_P1_MOVE_RIGHT SDL_SCANCODE_D
#define KEY_P1_FIRE_MISSILE SDL_SCANCODE_SPACE

#define KEY_P2_MOVE_UP SDL_SCANCODE_UP
#define KEY_P2_MOVE_DOWN SDL_SCANCODE_DOWN
#define KEY_P2_MOVE_LEFT SDL_SCANCODE_LEFT
#define KEY_P2_MOVE_RIGHT SDL_SCANCODE_RIGHT
#define KEY_P2_FIRE_MISSILE SDL_SCANCODE_KP_ENTER

class Inputs {

	bool quit;
	int mouse_x;
	int mouse_y;
	// Boolean array for all keys. See above definitions
	const Uint8 *key_states;

	// Returns true if ESC or 'X' button is pressed
	bool check_for_quit(SDL_Event event);

public:
	Inputs();
	void update();
	// Has the ESC key or 'X' button been pressed?
	bool get_quit();
	// Key codes defined above
	bool is_key_down(int key);
	bool is_key_down_player(int key, int player_num);
};

#endif