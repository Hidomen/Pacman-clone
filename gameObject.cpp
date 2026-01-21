#include "gameObject.h"



gameObject::gameObject(Map& map) : object_direction(Down), map(map) {
	
}



void gameObject::move(Direction given_direction) {

	//std::cout << "LEFT BORDER: " << map.border.left_pos << " RIGHT BORDER:"	<< map.border.right_pos << std::endl;
	//std::cout << "UP BORDER: "	 << map.border.up_pos << " DOWN BORDER: "	<< map.border.down_pos << std::endl;

	object_direction = given_direction;

	switch (given_direction){

	case Down:
		if (position.y + shape.getSize().y + step > map.border.down_pos) return; //position is based by top-left corner of shape
		if ('|' == map.checkCell({ position.x, position.y + shape.getSize().y + step })) return;

		shape.move({ 0, step });
		break;
	
	case Up:
		if (position.y - step < map.border.up_pos) return; //if future position is outside of border
		if ('|' == map.checkCell({ position.x,position.y - step })) return;

		shape.move({ 0, -step });
		break;

	case Right:
		if (position.x + shape.getSize().x + step > map.border.right_pos) return;
		if ('|' == map.checkCell({ position.x + shape.getSize().x + step , position.y })) return;

		shape.move({ step, 0 });
		break;

	case Left:
		if (position.x - step < map.border.left_pos) return;
		if ('|' == map.checkCell({ position.x - step , position.y })) return;

		shape.move({ -step, 0 });
		break;
	
	}

	position = shape.getPosition();


	std::cout << "POS: " << position.x << ", " << position.y << std::endl;

	

}