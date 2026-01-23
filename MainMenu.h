#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Button.h"

enum MenuState { sMainMenu, sMainOptions, sInGame, sPause, sInGameOptions };


class MainMenu
{
public:
	sf::RenderWindow& window;
	MenuState& state;
	MainMenu(sf::RenderWindow& window, MenuState& state, float width);


	int button_size;

	sf::Font font; //

	Button play;
	Button options;
	Button exit;
	

	//std::vector<sf::Text> buttons;
	//
	
	void update();
	void render();
};

