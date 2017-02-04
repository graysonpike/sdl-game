#include <stdbool.h>
#include "game.h"
#include "../entities/block.h"
#include "clock.h"
#include "../controls.h"
#include "../entities/character.h"

struct character *player_char;
float delta;

// Character speed in pixels per second
#define CHAR_SPEED (500.0f)

// Create game objects
void game_init() {

    // Used to measure time between cycles
    init_clock();

    // Player character
    player_char = create_character(WIDTH/2, HEIGHT/2);

}


// Returns true if ESC or 'X' button is pressed
bool check_for_quit(SDL_Event event) {
    if(event.type == SDL_QUIT) {
        return true;
    }
    if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
            case SDLK_ESCAPE:
                return true;
                break;
            default:
                break;
        }
    }
    return false;
}


// Move the player character based on key states
void move_character(const Uint8 *key_states, struct block *b, float delta) {

    if(key_states[KEY_MOVE_UP]) {
        move_block(b, 0.0f, -CHAR_SPEED, delta);
    } else if(key_states[KEY_MOVE_DOWN]) {
        move_block(b, 0.0f, CHAR_SPEED, delta);
    }
    if(key_states[KEY_MOVE_LEFT]) {
        move_block(b, -CHAR_SPEED, 0.0f, delta);
    } else if(key_states[KEY_MOVE_RIGHT]) {
        move_block(b, CHAR_SPEED, 0.0f, delta);
    }

}


// Main cycle running game logic (inputs, physics, mechanics, etc.)
bool game_update() {

    // Time since last cycle
    delta = get_delta();

    // EVENTS
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {

        // ESC or X button close the game
        if(check_for_quit(event)) {
            return false;
        }

    }

    // KEY STATES
    const Uint8 *key_states = SDL_GetKeyboardState(NULL);
    // Move the player character
    move_character(key_states, player_char->block, delta);
    // UPDATE ENTITIES
    update_block(player_char->block, delta);

    return true;
}


// Free memory of game objects
void game_quit() {
    destroy_character(player_char);
}