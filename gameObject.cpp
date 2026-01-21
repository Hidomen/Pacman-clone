#include "gameObject.h"



gameObject::gameObject(Map& map, borderList& border) : object_direction(Down), map(map), border(border) {
	
}



void gameObject::move(Direction given_direction) {

	std::cout << "LEFT BORDER: " << border.border_left << " RIGHT BORDER:"	<< border.border_right << std::endl;
	std::cout << "UP BORDER: "	 << border.border_up << " DOWN BORDER: "	<< border.border_down << std::endl;

	object_direction = given_direction;

	switch (given_direction){

	case Down:
		if (position.y + shape.getSize().y + speed > border.border_down) return; //position is based by top-left corner of shape

		shape.move({ 0, speed });
		break;
	
	case Up:
		if (position.y - speed < border.border_up) return; //if future position is outside of border

		shape.move({ 0, -speed });
		break;

	case Right:
		if (position.x + shape.getSize().x + speed > border.border_right) return;

		shape.move({ speed, 0 });
		break;

	case Left:
		if (position.x - speed < border.border_left) return;

		shape.move({ -speed, 0 });
		break;
	
	}

	position = shape.getPosition();


	std::cout << position.x << ", " << position.y << std::endl;
	std::cout << map.checkCell(position) << std::endl;

	//if (map.charToCell(map.checkCell(position)) == Wall) {
		//std::cout << "Wall" << std::endl;
	//}

}