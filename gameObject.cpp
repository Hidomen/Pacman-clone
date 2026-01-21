#include "gameObject.h"



gameObject::gameObject(Map& map, sf::RectangleShape& arena) : map(map), arena(arena) {
	object_direction = Down;
}


void gameObject::move(Direction given_direction) {
	object_direction = given_direction;


	switch (given_direction){

	case Down:
		shape.move({ 0, speed });
		break;
	
	case Up:
		shape.move({ 0, -speed });
		break;

	case Left:
		shape.move({ -speed, 0 });
		break;
	
	case Right:
		shape.move({ speed, 0 });
		break;
		
	}
	position = shape.getPosition();


	std::cout << position.x << ", " << position.y << std::endl;
	std::cout << map.checkCell(position) << std::endl;

	//if (map.charToCell(map.checkCell(position)) == Wall) {
		//std::cout << "Wall" << std::endl;
	//}

}