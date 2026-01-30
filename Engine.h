#pragma once

#include <SFML/Graphics.hpp>

#include "StateManager.h"


class Engine{
	

public:
	Engine();

	void run();
	

private:
	
	int mapID;
	sf::RenderWindow window;
	
	//int mapID;
	StateManager stateManager;
	//
	void handleEvents();
	void render();
};

