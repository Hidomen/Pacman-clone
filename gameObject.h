#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>



static float speed = grid_size;



static int width = grid_size * (board_cell_width + 3);
static int height = grid_size * (board_cell_height + 3);


enum Direction {Down, Up, Right, Left};

class gameObject{
protected:
	Map& map;
	borderList& border;
public:
	gameObject(Map& map, borderList& border);
	
	sf::Vector2f position;
	Direction object_direction;
	sf::RectangleShape shape;
//private:
	float border_down;
	float border_up;
	float border_right;
	float border_left;


	
	void move(Direction given_direction);

};

