#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

#include "Ghost.h"




class Game{
public:
	sf::RenderWindow& window;
	sf::RectangleShape arena;

	sf::Clock delayClock;
	sf::Clock timerClock; //cant start with 0

	float move_speed;
	float delay_time;
	float timer_time;
	bool isInit;

	borderList border;


	Map map;

	Player player;

	Ghost ghost1;
	Ghost ghost2;


	Game(sf::RenderWindow& window, int mapID);
	

	sf::VertexArray grid_lines;


	void inputSystem();

	void init();
	void update();
	void render();
};

