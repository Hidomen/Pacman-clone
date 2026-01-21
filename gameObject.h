#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>

static float step = grid_size;


//bunların burda ne işi var
static float width = grid_size * (board_cell_width + 4);
static float height = grid_size * (board_cell_height + 4);
//

enum Direction {Down, Up, Right, Left};

class gameObject{
protected:
	Map& map;

public:
	gameObject(Map& map);
	
	sf::Vector2f position;
	Direction object_direction;
	sf::RectangleShape shape;
//private:

	void move(Direction given_direction);

};

