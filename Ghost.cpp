#include "Ghost.h"


Ghost::Ghost(Map& map) : gameObject(map) {
	shape.setSize({ tileSize, tileSize });
	shape.setFillColor(sf::Color::Green);
	//shape.setPosition({50,50});

	
}