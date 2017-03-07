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
    if(player->get_x() > x) {
        x += speed * delta;
    } else if (player->get_x() < x) {
        x -= speed * delta;
    }
    if(player->get_y() > y) {
        y += speed * delta;
    } else if (player->get_y() < y) {
        y -= speed * delta;
    }
}

/*
void Crawler::render(float delta) {
    return;
}
*/