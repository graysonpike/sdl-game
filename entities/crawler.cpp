#include "crawler.h"
#include "player.h"

const int Crawler::w = 32;
const int Crawler::h = 32;
const std::string Crawler::texture_name = "crawler";

Crawler::Crawler(float x, float y) : Entity(x, y) {
    hitbox = new Hitbox(x, y, w, h);
    speed = 100;
}

std::string Crawler::get_texture_name() {
    return texture_name;
}

void Crawler::update(World *world) {
    Player *player = (Player*) (*world->get_entities())[0];
    float delta = world->get_delta();
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