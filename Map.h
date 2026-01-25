#pragma once

#include <SFML/Graphics.hpp>

constexpr int tile_size = 24;


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
	
	std::vector<sf::Sprite> tiles;


	
	sf::Texture pelletTexture;
	//sf::Sprite pelletSprite;

	sf::Texture wallTexture;
	//sf::Sprite wallSprite;
	sf::Texture emptyTexture;


	Map(int ID, borderList& border); //loads given ID map 


	CellType charToCell(char c);
	char cellToChar(CellType c);

	char checkCell(sf::Vector2f position);
	sf::Vector2i posToTile(sf::Vector2f position); //referenced by borders
	WallDirection wallPos(sf::Vector2i tilePos);

	void printMap();

private:
	
};

