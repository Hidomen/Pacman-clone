#include "Ghost.h"


Ghost::Ghost(Map& map, SoundManager& soundManager) : Entity(map, soundManager) {
	shape.setSize({ tileSize, tileSize });
	shape.setFillColor(sf::Color::Green);
	//shape.setPosition({50,50});

	
}

void Ghost::update() {
	float randTileX = rand() % 28;
	float randTileY = rand() % 31;

	Ghost::targetPosition = { randTileX, randTileY };
}