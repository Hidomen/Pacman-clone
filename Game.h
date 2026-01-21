#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

#include "Ghost.h"




class Game{
public:
	sf::RenderWindow& window;
	sf::RectangleShape arena;

	sf::Clock clock;
	float delayTime;

	borderList border;


	Map map;

	Player player;

	Ghost ghost1;
	Ghost ghost2;


	Game(sf::RenderWindow& window, int mapID);
	

	sf::VertexArray grid_lines;


	void inputSystem(float currentTime);

	void update();
	void render();
};

