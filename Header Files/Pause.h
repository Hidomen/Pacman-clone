#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class Pause
{
public:
	sf::RenderWindow& window;
	sf::Font& font;

	Pause(sf::RenderWindow& window, sf::Font& font);

	Button options;
	Button mainMenu;

	void update();
	void render();
};

