#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"

class Player : public Entity {
public:
	sf::RenderWindow& window;

	Player(Map& map, SoundManager& soundManager, sf::RenderWindow& window);

	int score; //high-score?
	int health; //3 for starting

	void update();
	void render();

	void move();

	Direction nextDirection;

	void pellet();
	void portal();
	void changeDirection(Direction direction);
	void checkRotation();
	//void portal(); //if its out of boundry then tp the opposite side
};

