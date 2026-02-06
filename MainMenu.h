#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Button.h"
#include "Globals.h"


class MainMenu
{
public:
	sf::RenderWindow& window;
	MenuState& state;
	MainMenu(sf::RenderWindow& window, MenuState& state, float width);


	int button_size;

	sf::Font font; //

	sf::Texture backgroundTexture;
	sf::Texture cursorTexture;

	sf::Sprite background;
	sf::Sprite cursor;
	sf::Vector2f cursorPos;
	bool cursorVis;

	Button play;
	Button options;
	Button exit;
	

	//std::vector<sf::Text> buttons;
	//
	
	void update();
	void render();
};

