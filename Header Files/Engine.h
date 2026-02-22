#pragma once

#include <SFML/Graphics.hpp>

#include "StateManager.h"


class Engine{
public:
	sf::Font font;

	Engine();

	void run();
	int mapID;

private:
	
	sf::RenderWindow window;
	
	//int mapID;
	StateManager stateManager;
	//


	void handleEvents();
	void render();
};

