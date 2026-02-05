#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"



class Ghost : public Entity{
public:
	Ghost(Map& map, SoundManager& soundManager);

	sf::Vector2f targetPosition;
	bool isEnergised;

	void update();
};

