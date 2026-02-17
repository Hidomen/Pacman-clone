#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

class SpriteManager
{
public:

	sf::Texture texture;
	sf::Sprite sprite;
	
	sf::RenderWindow& window;

	SpriteManager(sf::RenderWindow& window, EntityType entityType);
	
	void rotate(Direction direction);
	void render();
};

