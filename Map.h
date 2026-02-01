#pragma once

#include <SFML/Graphics.hpp>

#include "Globals.h"




static const int board_cell_height = 31;
static const int board_cell_width = 28;


enum CellType {Empty, Wall, Pellet, Portal, Door, Enrg, Out};

enum class WallDirection { Horizontal, Vertical, TopLeftCorner, TopRightCorner, BottomLeftCorner, BottomRightCorner };


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
	
	std::vector<sf::Sprite> tileVector; //make it 2D, or 2D reachable
	std::vector<bool> pelletVector; //if I can reach pellet from their sprite dont need

	sf::Texture pelletTexture;
	sf::Texture wallTexture;
	sf::Texture emptyTexture;


	Map(int ID, borderList& border); //loads given ID map 


	CellType charToCell(char c);
	char cellToChar(CellType c);


	char checkCellbyPos(sf::Vector2f position);
	CellType checkCellbyTile(sf::Vector2i tile);
	sf::Vector2i posToTile(sf::Vector2f position); //referenced by borders

	CellType positionToTile(sf::Vector2f position);

	sf::Vector2f posCentralize(sf::Vector2f position, sf::Vector2f objectSize);
	bool checkWallCollision(sf::Vector2f position, sf::RectangleShape objectHitbox, Direction direction);

	bool isOnGrid(sf::Vector2f position);

	void wallTexturer(sf::Vector2i tilePos);
	sf::Sprite getVector(sf::Vector2f position);

	void load();

private:
	
};

