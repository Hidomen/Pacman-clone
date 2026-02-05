#include "Entity.h"



Entity::Entity(Map& map, SoundManager& soundManager) : entityDirection(Direction::Left), map(map), soundManager(soundManager), sprite(sprite) {
	shape.setSize({ 24,24});
}




//void Entity::move(){}