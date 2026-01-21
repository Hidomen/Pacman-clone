#pragma once

#include <SFML/Graphics.hpp>

#include "Game.h"



class Engine{
	

public:
	Engine();

	void run();
	

private:
	
	int mapID;
	sf::RenderWindow window;
	
	//int mapID;
	
	Game game;
	//
	void handleEvents();
	void render();
	
	bool isOpen();


};

