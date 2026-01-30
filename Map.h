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
	
	std::vector<sf::Sprite> tileVector; //make it 2D, or 2D reachable
	std::vector<bool> pelletVector;
	//sf::Sprite tilles[board_cell_height][board_cell_width];
	//std::vector<std::vector<sf::Sprite>> spriteMap;

	sf::Texture pelletTexture;
	sf::Texture wallTexture;
	sf::Texture emptyTexture;


	Map(int ID, borderList& border); //loads given ID map 


	CellType charToCell(char c);
	char cellToChar(CellType c); // cancel it


	char checkCell(sf::Vector2f position);
	sf::Vector2i posToTile(sf::Vector2f position); //referenced by borders

	CellType positionToTile(sf::Vector2f position);


	void wallTexturer(sf::Vector2i tilePos);

	void load();

private:
	
};

