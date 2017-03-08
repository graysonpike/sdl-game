#include "crawler.h"
#include "player.h"

const int Crawler::w = 32;
const int Crawler::h = 32;
const std::string Crawler::texture_name = "crawler";

Crawler::Crawler(float x, float y, Player *player) : Entity(x, y) {
    hitbox = new Hitbox(x, y, w, h);
    speed = 100;
    this->player = player;
}

std::string Crawler::get_texture_name() {
    return texture_name;
}

void Crawler::update(float delta) {
    // The crawler will move toward the player at a constant speed.
    // The crawler will move in a direct line towards the player

    // If approximate distance is less than moving distance
    // just move to player coords
    float x_dist = player->get_x() - x;
    float y_dist = player->get_y() - y;
    if(pow(speed * delta, 2) >= x_dist * x_dist + y_dist * y_dist) {
        x = player->get_x();
        y = player->get_y();
    }
    // Otherwise, move along the direct line to the player
    else {
        float angle = atan2(player->get_y() - y, player->get_x() - x);
        x += delta * speed * cos(angle);
        y += delta * speed * sin(angle);
    }
}
