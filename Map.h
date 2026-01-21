#pragma once

#include <SFML/Graphics.hpp>

constexpr int tileSize = 24;


static const int board_cell_height = 31;
static const int board_cell_width = 28;


enum CellType {Empty, Wall, Food, Portal, Door, Enrg, Out};

struct borderList {

	float up_pos; //
	float down_pos;
	float right_pos;
	float left_pos; //

};



class Map{
public:
	int mapID;
	borderList& border;
	
	std::vector<sf::RectangleShape> tiles;
	

	Map(int ID, borderList& border); //loads given ID map 

	void printID();

	CellType charToCell(char c);
	char checkCell(sf::Vector2f position);
	sf::Vector2f posToTile(sf::Vector2f position); //referenced by borders

	void printMap();

private:
	
};

