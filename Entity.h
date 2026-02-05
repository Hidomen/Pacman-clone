#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>
#include "Globals.h"

#include "SoundManager.h"

//bunların burda ne işi var
static float width = tileSize * (board_cell_width + 4);
static float height = tileSize * (board_cell_height + 4);
//


class Entity{
protected:
	Map& map;
	SoundManager& soundManager;

public:
	Entity(Map& map, SoundManager& soundManager);
	
	sf::Vector2f position;
	sf::Vector2f targetPosition;

	sf::Vector2i lastTilePos;

	Direction entityDirection;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape shape;

//private:

	//void move();

};

