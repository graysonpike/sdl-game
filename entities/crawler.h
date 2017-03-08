#ifndef CRAWLER_H
#define CRAWLER_H

#include <string>
#include "../game/entity.h"
#include "../game/hitbox.h"
#include "player.h"

// Crawler enitiy. Follows player around the screen at a constant speed.

class Crawler: public Entity{

    static const int w, h;
    static const std::string texture_name;
    Player *player;
    // Speed in px/sec
    float speed;

public:
    Crawler(float x, float y, Player *player);
    void update(float delta);
    std::string get_texture_name();
};

#endif