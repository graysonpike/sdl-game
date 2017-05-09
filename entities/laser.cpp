#include <math.h>
#include "laser.h"
#include "player.h"
#include "../debug.h"

#define LIFETIME (0.9f) // (in seconds)

#define WIDTH 12
#define HEIGHT 20

// PUBLIC FUNCTIONS

Laser::Laser(float x, float y, float speed, float angle, int player_num,
                 int screen_w, int screen_h, std::vector<Entity*> *entities) : Entity(x, y, WIDTH, HEIGHT,
                 screen_w, screen_h) {

    this->w = WIDTH;
    this->h = HEIGHT;
    hitbox = new Hitbox(0, 0, w, h);
    time_alive = 0.0f;
    alive = true;
    this->speed = speed;
    this->angle = angle;
    this->screen_w = screen_w;
    this->screen_h = screen_h;
    this->player_num = player_num;
    this->entities = entities;

}

void Laser::update(float delta) {

    time_alive += delta;

    // Apply change in x and y directions
    x += delta * speed * cos(angle);
    y += delta * speed * sin(angle);

    check_bounds();

    hitbox->update_pos(x, y, angle);

}

void Laser::render(SDL_Renderer *renderer, Resources *resources,
                     float delta) {

    // Render hitbox corners if enabled from debug.h
    #ifdef DEBUG_RENDER_HITBOX_CORNERS
    hitbox->render_corners(renderer);
    #endif

    // Choose texture (changes missile color)
    SDL_Texture *texture;
    if(player_num == 1) {
        texture = resources->get_texture("laser1", 1);
    } else {
        texture = resources->get_texture("laser2", 1);
    }

    int texture_width, texture_height;
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    
    SDL_Rect dst = {
        (int)x,
        (int)y,
        texture_width,
        texture_height
    };

    // Convert angle to degrees for SDL_RenderCopyEx()
    float rect_angle = angle / M_PI * 180 + 90;

    SDL_RenderCopyEx(renderer, texture, NULL, &dst, rect_angle,
                     NULL, SDL_FLIP_NONE);

}

bool Laser::is_alive() {
    return time_alive < LIFETIME && alive;
}

const int Laser::get_id() {
    return 1;
}

// Lasers don't check for collisions
const bool Laser::collides() { return false; }

bool Laser::does_collide(int id) { return false; }

void Laser::collide_entity(Entity *entity) {

    switch(entity->get_id()) {
        case 0:
            if(((Player*)entity)->get_player_num() != player_num) {
                alive = false;
            }
            break;
        default:
            break;
    }
    
}

int Laser::get_player_num() {
    return player_num;
}