#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
	Button(std::string inputText, sf::Vector2f position, int button_size);

	float text_size;
	sf::Font font;


	sf::Text text;

	//sf::Vector2f hitboxBounds;
	sf::RectangleShape hitbox;

	bool update(sf::RenderWindow& window);

};

