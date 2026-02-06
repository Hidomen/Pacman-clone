#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

#include "Ghost.h"
#include "Globals.h"



class Game{
public:
	sf::RenderWindow& window; 
	sf::RectangleShape arena;

	SoundManager& soundManager;

	sf::Clock delayClock;
	sf::Clock timerClock; //cant start with 0

	float moveSpeed;
	float delayTime;
	float timerTime;

	borderList border;

	Map map;

	Player player;

	Ghost ghost1;
	Ghost ghost2;


	Game(sf::RenderWindow& window, SoundManager& soundManager, int mapID);
	

	sf::VertexArray gridLines;

	sf::Font font;
	float scoreSize;

	sf::Text score;
	sf::Text highScore;

	void inputSystem();

	void init();
	void update();
	void render();
};

