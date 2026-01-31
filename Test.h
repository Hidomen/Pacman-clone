#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Test
{
public:
	sf::RenderWindow window;
	Test();

	sf::RectangleShape rect;

	void run();
	void issue(sf::RectangleShape rect);
};

