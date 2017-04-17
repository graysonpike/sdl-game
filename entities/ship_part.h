#ifndef SHIPPART_H
#define SHIPPART_H

#include "../game/entity.h"
#include "../game/hitbox.h"

// Simple particle-like entity which is spawned which a Player explodes.
class ShipPart: public Entity {

    // Speed in px/sec
    float time_alive;
    float lifetime;
    float vx, vy;
    float angle;
    float rot_speed;
    int player_num;
    int type;

public:

    ShipPart(float x, float y, float vx, float vy, float rot_speed,
             float lifetime, int player_num, int type);
    void update(float delta);
    void render(SDL_Renderer *renderer, Resources *resources,
                float delta);
    bool is_alive();
    const int get_id();
    const bool collides();
    bool does_collide(int id);
    void collide_entity(Entity *entity);

};

#endif