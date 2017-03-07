#ifndef CRAWLER_H
#define CRAWLER_H

#include "../game/entity.h"
#include "../game/hitbox.h"
#include <string>

class Crawler: public Entity{

    static const int w, h;
    static const std::string texture_name;
    // Speed in px/sec
    float speed;

public:
    Crawler(float x, float y);
    void update(World *world);
    //void render(float delta);
    std::string get_texture_name();
};

#endif