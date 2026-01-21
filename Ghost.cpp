#include "Ghost.h"


Ghost::Ghost(Map& map, sf::RectangleShape& arena) : gameObject(map, arena) {
	shape.setSize({ 64, 64 });
	shape.setFillColor(sf::Color::Red);
	shape.setPosition({50,50});

	
}