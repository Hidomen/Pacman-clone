#include "Entity.h"



Entity::Entity(Map& map) : entityDirection(Direction::Left), map(map), sprite(sprite) {
	shape.setSize({ 24,24});
}




//void Entity::move(){}