#pragma once

#include <SFML/Graphics.hpp>

#include "Config.h"

enum CellType { Empty, Wall, Pellet, Portal, Door, Enrg, Out };

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
	int remainingPellet;

	sf::Texture pelletTexture;
	sf::Texture wallTexture;
	sf::Texture emptyTexture;

	sf::Texture testTexture;


	Map(int ID, borderList& border); //loads given ID map 


	CellType charToCell(char c);
	char cellToChar(CellType c);

	void pelletEaten(sf::Vector2i tile);
	char checkCellbyPos(sf::Vector2f position);
	CellType checkCellbyTile(sf::Vector2i tile);
	sf::Vector2i posToTile(sf::Vector2f position); //referenced by borders

	bool isOnGrid(sf::Vector2f position);

	void wallTexturer(sf::Vector2i tilePos);
	sf::Sprite getVector(sf::Vector2f position);

	void load();
	void clear(); //map cleared
private:
	
};

