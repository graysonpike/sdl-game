#ifndef PARTICLE_H
#define PARTICLE_H

#include "../game/entity.h"
#include "../game/hitbox.h"

class Particle: public Entity {

    // Speed in px/sec
    float time_alive;
    float lifetime;
    float vx, vy;
    int type;

public:
    Particle(float x, float y, float vx, float vy, float lifetime, int type);
    void update(float delta);
    void render(SDL_Renderer *renderer, Resources *resources, float delta);
    bool is_alive();
    const int get_id();
    const bool collides();
    bool does_collide(int id);
    void collide_entity(Entity *entity);
};

#endif