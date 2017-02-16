#include <SDL2/SDL.h>
#include "game.h"
#include "clock.h"
#include "../controls.h"

float delta;

int mouse_x = 0;
int mouse_y = 0;

const Uint8 *key_states;

// Create game objects
void game_init() {

    // Used to measure time between cycles
    init_clock();

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


// Handle state of the keyboard
void handle_keystate() {

    /* TODO: Implement with keystate handler
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
    */

}


void handle_mouse_down(SDL_Event event) {

    if(event.button.button == SDL_BUTTON_LEFT) {
        printf("left click\n");
    }

}


// Main cycle running game logic (inputs, physics, mechanics, etc.)
bool game_update() {

    // Reset delta since last cycle
    delta = get_delta();

    // EVENTS
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {

        // ESC or X button close the game
        if(check_for_quit(event)) {
            return false;
        }

        // Record mouse position when it moves
        if(event.type == SDL_MOUSEMOTION) {
            mouse_x = event.motion.x;
            mouse_y = event.motion.y;
        }

        if(event.type == SDL_MOUSEBUTTONDOWN) {
            handle_mouse_down(event);
        }

    }

    // KEY STATES
    key_states = SDL_GetKeyboardState(NULL);
    handle_keystate();

    // TODO: Update entities

    return true;
}


// Free memory of game objects
void game_quit() {
    // TODO: Free game objects
}