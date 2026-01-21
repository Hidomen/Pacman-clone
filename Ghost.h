#pragma once

#include <SFML/Graphics.hpp>
#include "gameObject.h"



class Ghost : public gameObject{
public:
	Ghost(Map& map, sf::RectangleShape& arena);

	sf::Vector2f targetPosition;
	bool isEnergised;
};

