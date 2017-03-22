#include <math.h>
#include "player.h"
#include "missile.h"

#define MISSILE_DELAY (0.5f)

const int Player::w = 36;
const int Player::h = 40;

Player::Player(float x, float y, int player_num, int screen_w, int screen_h, std::vector<Entity*> *entities) : Entity(x, y) {
    hitbox = new Hitbox(x, y, w, h);
    vx = vy = 0.0f;
    turn_speed = 3.0f;
    linear_accel = 300.0f;
    max_speed = 500.0f;
    angle = 0;
    missile_cooldown = 0.0f;
    this->player_num = player_num;
    this->screen_w = screen_w;
    this->screen_h = screen_h;
    this->entities = entities;
}

float Player::get_center_x() {
    return x + w/2;
}

float Player::get_center_y() {
    return y + h/2;
}

void Player::update(float delta) {
    // Apply change in x and y directions
    x += delta * vx;
    y += delta * vy;
    // Enforce speed limit
    if(vx > max_speed) {
        vx = max_speed;
    }
    if(vy > max_speed) {
        vy = max_speed;
    }
    if(vx < -max_speed) {
        vx = -max_speed;
    }
    if(vy < -max_speed) {
        vy = -max_speed;
    }
    // Check for going out of bounds
    if(this->get_center_x() < 0) {
        x = screen_w - w/2;
    } else if (this->get_center_x() > screen_w) {
        x = 0 - w/2;
    }
    if(this->get_center_y() < 0) {
        y = screen_h - h/2;
    } else if (this->get_center_y() > screen_h) {
        y = 0 - h/2;
    }
}

void Player::render(SDL_Renderer *renderer, Resources *resources, float delta) {
    int texture_width, texture_height;
    SDL_Texture *texture = resources->get_texture("ship1", 1);
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    SDL_Rect dst = {
        (int)x,
        (int)y,
        texture_width,
        texture_height
    };
    SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle / M_PI * 180 + 90, NULL, SDL_FLIP_NONE);
}

void Player::handle_inputs(float delta, Inputs *inputs) {
    // Movement Controls
    if(inputs->is_key_down(KEY_MOVE_UP)) {
        vx += delta * linear_accel * cos(angle);
        vy += delta * linear_accel * sin(angle);
    } else if (inputs->is_key_down(KEY_MOVE_DOWN)) {
        vx -= delta * linear_accel * cos(angle);
        vy -= delta * linear_accel * sin(angle);
    }
    if(inputs->is_key_down(KEY_MOVE_LEFT)) {
        angle -= delta * turn_speed;
    } else if (inputs->is_key_down(KEY_MOVE_RIGHT)) {
        angle += delta * turn_speed;
    }
    // Shooting
    if(inputs->is_key_down(KEY_FIRE_MISSILE)) {
        float speed = 100;
        entities->push_back(new Missile(x, y, speed, angle, screen_w, screen_h));
    }
}