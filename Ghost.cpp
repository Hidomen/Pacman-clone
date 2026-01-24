#include "Ghost.h"


Ghost::Ghost(Map& map) : gameObject(map) {
	shape.setSize({ tile_size, tile_size });
	shape.setFillColor(sf::Color::Green);
	//shape.setPosition({50,50});

	
}