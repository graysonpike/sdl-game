#include "missile.h"
#include <math.h>

#define LIFETIME (3.0f) // (in seconds)

const int Missile::w = 12;
const int Missile::h = 20;

Missile::Missile(float x, float y, float speed, float angle, int player_num, int screen_w, int screen_h) : Entity(x, y) {
    hitbox = new Hitbox(x, y, w, h);
    time_alive = 0.0f;
    this->speed = speed;
    this->angle = angle;
    this->screen_w = screen_w;
    this->screen_h = screen_h;
    this->player_num = player_num;
}

float Missile::get_center_x() {
    return x + w/2;
}

float Missile::get_center_y() {
    return y + h/2;
}

void Missile::update(float delta) {
    time_alive += delta;
    // Apply change in x and y directions
    x += delta * speed * cos(angle);
    y += delta * speed * sin(angle);
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

void Missile::render(SDL_Renderer *renderer, Resources *resources, float delta) {
    int texture_width, texture_height;
    SDL_Texture *texture;
    if(player_num == 1) {
        texture = resources->get_texture("missile1", 1);
    } else {
        texture = resources->get_texture("missile2", 1);
    }
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    SDL_Rect dst = {
        (int)x,
        (int)y,
        texture_width,
        texture_height
    };
    SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle / M_PI * 180 + 90, NULL, SDL_FLIP_NONE);
}

bool Missile::is_alive() {
    return time_alive < LIFETIME;
}