#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>
#include "Config.h"

#include "SoundManager.h"

class Entity {

protected:
	Map& map;
	SoundManager& soundManager;

public:
	Entity(Map& map, SoundManager& soundManager);

	EntityType entityType;
	
	sf::Vector2f position;
	sf::Vector2f nextStep;
	sf::Vector2f targetPosition;

	sf::Vector2i lastTilePos;

	Direction entityDirection;

	sf::RectangleShape shape;

	Direction nextDirection;

	void portal();
	void changeDirection(Direction direction);
	void checkRotation();

	void computeNextPosition();
	void applyMovement();
//private:

	//void move();

};

