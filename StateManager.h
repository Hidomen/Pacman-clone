#pragma once

#include <iostream>

#include "MainMenu.h"
#include "Game.h"
#include "Pause.h"

#include "Globals.h"

#include "SoundManager.h"


class StateManager{
public:
	sf::RenderWindow& window;
	sf::Font& font;

	StateManager(sf::RenderWindow& window, sf::Font& font);

	SoundManager soundManager;

	MenuState contState;
	MenuState initState; //goes to funcs.

	MainMenu mainMenu;
	Game game;
	Pause pause;

	void changeInitState(MenuState newState);
	void changeContState(MenuState newState);
	void update();
};

