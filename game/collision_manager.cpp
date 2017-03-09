#include "collision_manager.h"

void CollisionManager::check_collisions(std::vector<Entity*> *entities) {
	// Check for collisions with the player
	Hitbox *player = (*entities)[0]->get_hitbox();
	for(int i = 1; i < entities->size(); i++) {
		
	}
		
}