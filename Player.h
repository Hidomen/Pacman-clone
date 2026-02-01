#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"


class Player : public Entity {
public:

	Player(Map& map);

	int pelletCount;
	int score; //high-score?

	void update();

	void move();

	Direction nextDirection;

	void portal();
	void changeDirection(Direction direction);
	void checkRotation();
	//void portal(); //if its out of boundry then tp the opposite side
};

