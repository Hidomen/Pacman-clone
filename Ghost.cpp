#include "Ghost.h"


Ghost::Ghost(Map& map) : gameObject(map) {
	shape.setSize({ tile_size, tile_size });
	shape.setFillColor(sf::Color::Green);
	//shape.setPosition({50,50});

	
}

void Ghost::update() {
	float randTileX = rand() % 28;
	float randTileY = rand() % 31;

	Ghost::targetPosition = { randTileX, randTileY };
}