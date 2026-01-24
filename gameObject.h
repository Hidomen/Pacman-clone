#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>

static float step = tile_size;


//bunların burda ne işi var
static float width = tile_size * (board_cell_width + 4);
static float height = tile_size * (board_cell_height + 4);
//

enum class Direction {Down, Up, Right, Left};

class gameObject{
protected:
	Map& map;

public:
	gameObject(Map& map);
	
	sf::Vector2f position;

	Direction object_direction;
	Direction next_direction;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape shape;
//private:

	void move();
	void changeDirection(Direction new_direction);
	void checkRotation();

};

