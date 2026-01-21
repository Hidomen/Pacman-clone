#pragma once

#include <SFML/Graphics.hpp>

constexpr int grid_size = 24;


static const int board_cell_height = 31;
static const int board_cell_width = 28;


enum CellType {Empty, Wall, Food, Portal, Door, Enrg, Out};

struct borderList {

	int up_pos; //
	int down_pos;
	int right_pos;
	int left_pos; //

};



class Map{
public:
	int mapID;
	borderList& border;
	
	std::vector<sf::RectangleShape> tiles;
	

	Map(int ID, borderList& border); //loads given ID map 

	void printID();

	CellType charToCell(char c);
	char checkCell(sf::Vector2i position);
	sf::Vector2i posToTile(sf::Vector2i position); //referenced by borders

	void printMap();

private:
	
};

