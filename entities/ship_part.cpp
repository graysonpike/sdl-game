#include "ship_part.h"

ShipPart::ShipPart(float x, float y, float vx, float vy, float rot_speed,
                   float lifetime, int player_num, int type, int screen_w,
                   int screen_h) : Entity(x, y, 4, 4, screen_w, screen_h) {

    time_alive = 0.0f;
    angle = 0.0f;
    this->vx = vx;
    this->vy = vy;
    this->rot_speed = rot_speed;
    this->lifetime = lifetime;
    this->player_num = player_num;
    this->type = type;

}

void ShipPart::update(float delta) {

    time_alive += delta;
    x += vx * delta;
    y += vy * delta;
    angle += rot_speed * delta;

    check_bounds();

}

void ShipPart::render(SDL_Renderer *renderer, Resources *resources,
                      float delta) {

    int texture_width, texture_height;
    float alpha_level = (lifetime - time_alive) / lifetime * 255.0f;
    SDL_Texture *texture;
    if(player_num == 1) {
        texture = resources->get_texture("ship1_piece", type);
    } else {
        texture = resources->get_texture("ship2_piece", type);
    }

    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    SDL_Rect dst = {
        (int) (x - texture_width / 2.0f),
        (int) (y - texture_height / 2.0f),
        texture_width,
        texture_height
    };
    SDL_SetTextureAlphaMod(texture, (int)alpha_level);
    SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle, NULL, SDL_FLIP_NONE);

}

bool ShipPart::is_alive() {
    return time_alive <= lifetime;
}

const int ShipPart::get_id() {
    return 3;
}

const bool ShipPart::collides() {
    return false;
}

bool ShipPart::does_collide(int id) {
    return false;
}

void ShipPart::collide_entity(Entity *entity) {}