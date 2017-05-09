#ifndef LASER_H
#define LASER_H

#include "../game/entity.h"
#include "../game/hitbox.h"
#include <string>

// Laser that travels in a straight line from where it was fired at a given
// angle. Dies upon colliding with a Player with a different player_num or
// after 3 seconds. Does not check for collisions. If the laser moves out of
// screen bounds will wrap to the other side.
class Laser: public Entity {

    // References
    std::vector<Entity*> *entities;

    float speed; // Speed in px/sec
    float angle;
    float time_alive;
    int player_num;
    bool alive;

public:

    Laser(float x, float y, float speed, float angle, int player_num,
            int screen_w, int screen_h, std::vector<Entity*> *entities);
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