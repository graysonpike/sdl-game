#include "particle.h"

Particle::Particle(float x, float y) : Entity(x, y) {
    time_alive = 0.0f;
}

void Particle::update(float delta) {
    time_alive += delta;
}

void Particle::render(SDL_Renderer *renderer, Resources *resources, float delta) {
    int texture_width, texture_height;
    SDL_Texture *texture = resources->get_texture("particle", frame);

    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    SDL_Rect dst = {
        (int) (x - texture_width / 2.0f),
        (int) (y - texture_height / 2.0f),
        texture_width,
        texture_height
    };
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