#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class Pause
{
public:
	sf::RenderWindow& window;

	Pause(sf::RenderWindow& window);

	Button options;
	Button mainMenu;

	void update();
	void render();
};

