#ifndef MISSILE_H
#define MISSILE_H

#include "../game/entity.h"
#include "../game/hitbox.h"
#include <string>

// Missile that travels in a straight line from where it was
// fired at a given angle. Dies upon colliding with Player,
// does not check for collisions. Dies after 3 seconds.
class Missile: public Entity {

    static const int w, h;
    float speed; // Speed in px/sec
    float angle;
    int screen_w, screen_h;
    float time_alive;
    int player_num;
    bool alive;

    float get_center_x();
    float get_center_y();

public:

    // Missile entity at (x, y). Travels straight at (speed) px/s at
    // (angle) radians. Belongs to player (player_num).
    Missile(float x, float y, float speed, float angle, int player_num,
            int screen_w, int screen_h);

    // Moves the missile.
    // If the missile moves out of screen bounds will wrap to the other side.
    void update(float delta);

    void render(SDL_Renderer *renderer, Resources *resources, float delta);

    // Missile can die from colliding with a Player of a different player_num
    // or living >3 seconds.
    bool is_alive();
    
    const int get_id();

    // Missiles don't check for collisions
    const bool collides();

    // Unused
    bool does_collide(int id);

    // If a missile collides with a Player with a different (player_num),
    // it will die.
    void collide_entity(Entity *entity);

    int get_player_num();

};

#endif