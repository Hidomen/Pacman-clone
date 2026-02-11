#include "Ghost.h"


Ghost::Ghost(Map& map, SoundManager& soundManager) : Entity(map, soundManager) {
	shape.setSize({ tileSize, tileSize });
	shape.setFillColor(sf::Color::Green);
	//shape.setPosition({50,50});

	entityType = EntityType::Ghost;
}

void Ghost::update() {
	
}

void Ghost::moveSet(std::vector<Entity *>& entityList) {
	/*
	float randTileX = rand() % 28;
	float randTileY = rand() % 31;

	Ghost::targetPosition = { randTileX, randTileY };
	
	
	*/

	int randDir = rand() % 4;
	nextDirection = static_cast<Direction>(randDir);

	//move();
}