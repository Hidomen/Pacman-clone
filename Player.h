#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"

class Player : public Entity {
public:

	Player(Map& map, SoundManager& soundManager);

	int score; //high-score?
	int health; //3 for starting


	void update();

	void move();

	Direction nextDirection;

	void pellet();
	void portal();
	void changeDirection(Direction direction);
	void checkRotation();
	//void portal(); //if its out of boundry then tp the opposite side
};

