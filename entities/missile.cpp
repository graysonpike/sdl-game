#include <math.h>
#include "missile.h"
#include "player.h"
#include "../debug.h"

#define LIFETIME (3.0f) // (in seconds)

#define TURNSPEED 2.0f // in rad/sec

#define WIDTH 12
#define HEIGHT 20

// PUBLIC FUNCTIONS

Missile::Missile(float x, float y, float speed, float angle, int player_num,
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

void Missile::update(float delta) {

    time_alive += delta;

    // Steer towards the enemy player
    if(angle < -M_PI) {
        angle = angle + M_PI * 2;
    } else if(angle > M_PI) {
        angle = angle - M_PI * 2;
    }

    for(int i = 0; i < entities->size(); i++) {
        if((*entities)[i]->get_id() == 0 && ((Player*)(*entities)[i])->get_player_num() != player_num) {
            float enemy_x = (*entities)[i]->get_x();
            float enemy_y = (*entities)[i]->get_y();

            float angle_between = atan2(enemy_y - y, enemy_x - x);

            if(angle > angle_between) {
                if(angle - angle_between < M_PI) {
                    angle -= TURNSPEED * delta;
                } else {
                    angle += TURNSPEED * delta;
                }
            } else {
                if(angle_between - angle < M_PI) {
                    angle += TURNSPEED * delta;
                } else {
                    angle -= TURNSPEED * delta;
                }
            }

        }
    }

    // Apply change in x and y directions
    x += delta * speed * cos(angle);
    y += delta * speed * sin(angle);

    check_bounds();

    hitbox->update_pos(x, y, angle);

}

void Missile::render(SDL_Renderer *renderer, Resources *resources,
                     float delta) {

    // Render hitbox corners if enabled from debug.h
    #ifdef DEBUG_RENDER_HITBOX_CORNERS
    hitbox->render_corners(renderer);
    #endif

    // Choose texture (changes missile color)
    SDL_Texture *texture;
    if(player_num == 1) {
        texture = resources->get_texture("missile1", 1);
    } else {
        texture = resources->get_texture("missile2", 1);
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

bool Missile::is_alive() {
    return time_alive < LIFETIME && alive;
}

const int Missile::get_id() {
    return 1;
}

// Missiles don't check for collisions
const bool Missile::collides() { return false; }

bool Missile::does_collide(int id) { return false; }

void Missile::collide_entity(Entity *entity) {
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

int Missile::get_player_num() {
    return player_num;
}