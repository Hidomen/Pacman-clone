#pragma once

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "MainMenu.h"
#include "Pause.h"

enum MenuState {sMainMenu, sMainOptions, sInGame,  sPause, sInGameOptions};

class Engine{
	

public:
	Engine();

	void run();
	

private:
	MenuState state;
	
	int mapID;
	sf::RenderWindow window;
	
	//int mapID;

	MainMenu mainMenu;
	Game game;
	Pause pause;
	//
	void handleEvents();
	void render();
	
	bool isOpen();


};

