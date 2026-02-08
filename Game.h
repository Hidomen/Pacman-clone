#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

#include "Ghost.h"
#include "Globals.h"


class Game{
public:
	sf::RenderWindow& window; 
	SoundManager& soundManager;
	sf::Font& font;

	Game(sf::RenderWindow& window, SoundManager& soundManager, sf::Font& font, int mapID);

	sf::RectangleShape arena;

	sf::Clock delayClock;
	sf::Clock timerClock; //cant start with 0

	float moveSpeed;
	float delayTime;
	float timerTime;

	borderList border;

	Map map;

	Player player;

	Ghost ghost1, ghost2, ghost3, ghost4;

	std::vector<Entity *> entityList;

	sf::VertexArray gridLines;

	float scoreSize;

	sf::Text score;
	sf::Text highScore;

	void inputSystem();

	void init();
	void update();
	void render();
};

