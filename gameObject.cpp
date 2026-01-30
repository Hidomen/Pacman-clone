#include "gameObject.h"



gameObject::gameObject(Map& map) : objectDirection(Direction::Left), nextDirection(objectDirection), map(map), sprite(sprite) {
	shape.setSize({ 23.99,23.99});
}

void gameObject::changeDirection(Direction new_direction) {
	if (new_direction == objectDirection) return;

	nextDirection = new_direction;
	//update sprite //

}

void gameObject::checkRotation() { // check for copy paste situation

	switch (nextDirection){

	case Direction::Down:
		if (Wall == map.checkCell({position.x, position.y + shape.getSize().y + step})) return;
		break;

	case Direction::Up:
		if (Wall == map.checkCell({ position.x,position.y - step })) return;
		break;

	case Direction::Right:
		if (Wall == map.checkCell({ position.x + shape.getSize().x + step , position.y })) return;
		break;

	case Direction::Left:
		if (Wall == map.checkCell({ position.x - step , position.y })) return;
		break;
	}
	
	objectDirection = nextDirection;
}

//void gameObject::move(){}