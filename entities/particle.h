#ifndef PARTICLE_H
#define PARTICLE_H

#include "../game/entity.h"
#include "../game/hitbox.h"

// Particles are small dots that move at a set (vx, vy).
// There are 3 types (different colors). They die after (lifetime)
// seconds, and fade (with decreasing opacity) as they age.
class Particle: public Entity {

    float time_alive;
    float lifetime;
    float vx, vy; // Speed in px/s
    int type;

public:

    Particle(float x, float y, float vx, float vy, float lifetime, int type,
             int screen_w, int screen_h);
    void update(float delta);
    void render(SDL_Renderer *renderer, Resources *resources, float delta);
    bool is_alive();
    const int get_id();
    const bool collides();
    bool does_collide(int id);
    void collide_entity(Entity *entity);
};

#endif