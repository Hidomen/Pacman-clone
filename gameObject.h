#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>



static float speed = grid_size;



static int width = grid_size * (board_cell_width);
static int height = grid_size * (board_cell_height);


enum Direction {Down,Up,Left,Right} ;

class gameObject{
protected:
	Map& map;
	sf::RectangleShape& arena;

public:
	gameObject(Map& map, sf::RectangleShape& arena);
	
	sf::Vector2f position;
	Direction object_direction;
	sf::RectangleShape shape;
//private:
	
	void move(Direction given_direction);

};

