#include "hitbox.h"

// Size of rects drawn on corners by render_corners()
#define POINT_SIZE 6

Hitbox::Hitbox(float x, float y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Hitbox::update_pos(float x, float y, float angle) {
	angle = -angle;
	// Apply offsets to new position
	this->x = x + x_offset;
	this->y = y + y_offset;
	// Set new angle
	this->angle = angle;
	// Calculate new corners
	tl.x = x;
	tl.y = y;

	tr.x = x + cos(angle) * w;
	tr.y = y - sin(angle) * w;

	bl.x = x + sin(angle) * h;
	bl.y = y + cos(angle) * h;

	br.x = x + cos(angle) * w + sin(angle) * h;
	br.y = y - sin(angle) * w + cos(angle) * h;
}

void Hitbox::render_corners(SDL_Renderer * renderer) {
	// Set draw color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	// Create rectangles over each corner
	SDL_Rect tl_rect = { tl.x - POINT_SIZE / 2, tl.y - POINT_SIZE / 2, POINT_SIZE, POINT_SIZE };
	SDL_Rect tr_rect = { tr.x - POINT_SIZE / 2, tr.y - POINT_SIZE / 2, POINT_SIZE, POINT_SIZE };
	SDL_Rect bl_rect = { bl.x - POINT_SIZE / 2, bl.y - POINT_SIZE / 2, POINT_SIZE, POINT_SIZE };
	SDL_Rect br_rect = { br.x - POINT_SIZE / 2, br.y - POINT_SIZE / 2, POINT_SIZE, POINT_SIZE };
	// Draw rectangles
	SDL_RenderFillRect(renderer, &tl_rect);
	SDL_RenderFillRect(renderer, &tr_rect);
	SDL_RenderFillRect(renderer, &bl_rect);
	SDL_RenderFillRect(renderer, &br_rect);
}