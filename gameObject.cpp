#include "gameObject.h"



gameObject::gameObject(Map& map) : object_direction(Down), map(map) {
	
}



void gameObject::move(Direction given_direction) {

	std::cout << "LEFT BORDER: " << map.border.left_pos << " RIGHT BORDER:"	<< map.border.right_pos << std::endl;
	std::cout << "UP BORDER: "	 << map.border.up_pos << " DOWN BORDER: "	<< map.border.down_pos << std::endl;

	object_direction = given_direction;

	switch (given_direction){

	case Down:
		if (position.y + shape.getSize().y + speed > map.border.down_pos) return; //position is based by top-left corner of shape

		shape.move({ 0, speed });
		break;
	
	case Up:
		if (position.y - speed < map.border.up_pos) return; //if future position is outside of border

		shape.move({ 0, -speed });
		break;

	case Right:
		if (position.x + shape.getSize().x + speed > map.border.right_pos) return;

		shape.move({ speed, 0 });
		break;

	case Left:
		if (position.x - speed < map.border.left_pos) return;

		shape.move({ -speed, 0 });
		break;
	
	}

	position = shape.getPosition();


	std::cout << position.x << ", " << position.y << std::endl;
	std::cout << map.checkCell((sf::Vector2i)position) << std::endl;

	//if (map.charToCell(map.checkCell(position)) == Wall) {
		//std::cout << "Wall" << std::endl;
	//}

}