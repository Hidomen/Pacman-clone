#include "gameObject.h"



gameObject::gameObject(Map& map) : object_direction(Direction::Left), next_direction(object_direction), map(map), sprite(sprite) {
	shape.setSize({ 23,23 });
}

void gameObject::changeDirection(Direction new_direction) {
	if (new_direction == object_direction) return;

	next_direction = new_direction;
	//update sprite //

}

void gameObject::checkRotation() { // check for copy paste situation

	switch (next_direction){

	case Direction::Down:
		if (map.cellToChar(Wall) == map.checkCell({position.x, position.y + shape.getSize().y + step})) return;
		break;

	case Direction::Up:
		if (map.cellToChar(Wall) == map.checkCell({ position.x,position.y - step })) return;
		break;

	case Direction::Right:
		if (map.cellToChar(Wall) == map.checkCell({ position.x + shape.getSize().x + step , position.y })) return;
		break;

	case Direction::Left:
		if (map.cellToChar(Wall) == map.checkCell({ position.x - step , position.y })) return;
		break;
	}
	
	object_direction = next_direction;
}

void gameObject::move() {

	//std::cout << "LEFT BORDER: " << map.border.left_pos << " RIGHT BORDER:"	<< map.border.right_pos << std::endl;
	//std::cout << "UP BORDER: "	 << map.border.up_pos << " DOWN BORDER: "	<< map.border.down_pos << std::endl;

	//std::cout << "NEXT DIR: " << next_direction << "   OBJ. DIR: " << object_direction << std::endl;

	checkRotation();

	switch (object_direction){

	case Direction::Down:
		//position is based by top-left corner of shape
		if ('|' == map.checkCell({ position.x, position.y + shape.getSize().y + step })) return;
		shape.move({ 0, step });
		break;
	
	case Direction::Up:
		//if future position is outside of border
		if (map.cellToChar(Wall) == map.checkCell({ position.x,position.y - step })) return;
		shape.move({ 0, -step });
		break;

	case Direction::Right:
		if (map.cellToChar(Wall) == map.checkCell({ position.x + shape.getSize().x + step , position.y })) return;
		shape.move({ step, 0 });
		break;

	case Direction::Left:
		if (map.cellToChar(Wall) == map.checkCell({ position.x - step , position.y })) return;
		shape.move({ -step, 0 });
		break;
	
	}
	position = shape.getPosition();

	//std::cout << "MOVED POS: " << position.x << ", " << position.y << std::endl;
}