#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>
#include "Globals.h"



//bunların burda ne işi var
static float width = tileSize * (board_cell_width + 4);
static float height = tileSize * (board_cell_height + 4);
//


class gameObject{
protected:
	Map& map;

public:
	gameObject(Map& map);
	
	sf::Vector2f position;
	sf::Vector2f targetPosition;

	Direction objectDirection;
	Direction	nextDirection;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape shape;

//private:

	//void move();
	void changeDirection(Direction new_direction);
	void checkRotation();

};

