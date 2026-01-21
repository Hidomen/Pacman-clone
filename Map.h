#pragma once

#include <SFML/Graphics.hpp>

constexpr int grid_size = 24;


static const int board_cell_height = 31;
static const int board_cell_width = 28;


enum CellType {Empty, Wall, Food, Portal, Door, Enrg, Out};

struct borderList {

	int border_up; //
	int border_down;
	int border_right;
	int border_left; //

};


//typedef enum string[64][64] MapLib;

class Map{
public:
	int mapID;
	Map(int ID); //loads given ID map 

	void printID();
	CellType charToCell(char c);
	char checkCell(sf::Vector2f position);
	sf::Vector2i posToTile(sf::Vector2f position);
private:
	
};

