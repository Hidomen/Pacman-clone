#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class MainMenu
{
public:
	sf::RenderWindow& window;
	MainMenu(sf::RenderWindow& window, float width);


	int button_size;

	sf::Font font;

	sf::Text play;
	sf::Text options;
	sf::Text exit;

	//std::vector<sf::Text> buttons;
	//
	
	void update();
	void render();
};

