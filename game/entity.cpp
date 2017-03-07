#include "entity.h"

Entity::Entity(float x, float y) {
	this->x = x;
	this->y = y;
}

float Entity::get_x() {
	return x;
}

float Entity::get_y() {
	return y;
}

Hitbox* Entity::get_hitbox() {
	hitbox->update_pos(x, y);
	return hitbox;
}

void Entity::move_offset(float x, float y) {
	this->x += x;
	this->y += y;
}

void Entity::render(SDL_Renderer *renderer, Resources *resources, float delta) {
    int texture_width, texture_height;
    SDL_Texture *texture = resources->get_texture(get_texture_name());
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    SDL_Rect dst = {
        (int)x,
        (int)y,
        texture_width,
        texture_height
    };
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

Entity::~Entity() {
	delete hitbox;
}
