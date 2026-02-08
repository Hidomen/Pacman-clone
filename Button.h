#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
	sf::RenderWindow& window;
	sf::Font& font;
	Button(sf::RenderWindow& window, sf::Font& font, std::string inputText, sf::Vector2f position, int textSize);


	sf::Text text;

	//sf::Vector2f hitboxBounds;
	sf::RectangleShape hitbox;

	bool hover();
	bool isClicked();

};