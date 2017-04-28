#ifndef MISSILE_H
#define MISSILE_H

#include "../game/entity.h"
#include "../game/hitbox.h"
#include <string>

// Missile that travels in a straight line from where it was fired at a given
// angle. Dies upon colliding with a Player with a different player_num or
// after 3 seconds. Does not check for collisions. If the missile moves out of
// screen bounds will wrap to the other side.
class Missile: public Entity {

    float speed; // Speed in px/sec
    float angle;
    int screen_w, screen_h;
    float time_alive;
    int player_num;
    bool alive;

public:

    Missile(float x, float y, float speed, float angle, int player_num,
            int screen_w, int screen_h);
    void update(float delta);
    void render(SDL_Renderer *renderer, Resources *resources, float delta);
    bool is_alive();
    const int get_id();
    const bool collides();
    bool does_collide(int id);
    void collide_entity(Entity *entity);
    int get_player_num();

};

#endif