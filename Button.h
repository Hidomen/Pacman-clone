#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

enum class MenuState { MainMenu, MainOptions, InGame, Pause, InGameOptions, Exit };

class Button
{
public:
	sf::RenderWindow& window;
	Button(sf::RenderWindow& window, std::string inputText, sf::Vector2f position, int button_size);

	float text_size;
	sf::Font font;


	sf::Text text;

	//sf::Vector2f hitboxBounds;
	sf::RectangleShape hitbox;

	bool hover();
	bool isClicked();

};

