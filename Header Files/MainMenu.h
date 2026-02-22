#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Button.h"
#include "Config.h"


class MainMenu {
public:
	sf::RenderWindow& window;
	MenuState& state;
	sf::Font& font;

	MainMenu(sf::RenderWindow& window, MenuState& state, sf::Font& font);

	int textSize;

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

