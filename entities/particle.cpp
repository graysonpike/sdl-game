#include "particle.h"

Particle::Particle(float x, float y, float vx, float vy, float lifetime,
                   int type, int screen_w, int screen_h)
                   : Entity(x, y, 4, 4, screen_w, screen_h) {

    time_alive = 0.0f;
    this->vx = vx;
    this->vy = vy;
    this->lifetime = lifetime;
    this->type = type;

}

void Particle::update(float delta) {

    time_alive += delta;
    x += vx * delta;
    y += vy * delta;

    check_bounds();

}

void Particle::render(SDL_Renderer *renderer, Resources *resources,
                      float delta) {

    float alpha_level = (lifetime - time_alive) / lifetime * 255.0f;

    SDL_Texture *texture = resources->get_texture("particle", type);

    int texture_width, texture_height;
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    SDL_Rect dst = {
        (int) (x - texture_width / 2.0f),
        (int) (y - texture_height / 2.0f),
        texture_width,
        texture_height
    };

    SDL_SetTextureAlphaMod(texture, alpha_level);
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    
}

bool Particle::is_alive() {
    return time_alive <= lifetime;
}

const int Particle::get_id() {
    return 2;
}

const bool Particle::collides() {
    return false;
}

bool Particle::does_collide(int id) {
    return false;
}

void Particle::collide_entity(Entity *entity) {}