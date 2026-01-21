#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

#include "Ghost.h"





class Game{
public:
	sf::RenderWindow& window;
	sf::RectangleShape arena;


	Game(sf::RenderWindow& window, int mapID);

	Map map;
	Player player;
	


	Ghost ghost1;
	Ghost ghost2;

	sf::VertexArray grid_lines;


	void inputSystem();

	void update();
	void render();
};

