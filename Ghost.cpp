#include "Ghost.h"


Ghost::Ghost(Map& map) : gameObject(map) {
	shape.setSize({ 64, 64 });
	shape.setFillColor(sf::Color::Red);
	shape.setPosition({50,50});

	
}