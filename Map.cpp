#include "Map.h"
#include <iostream>


std::string map2[board_cell_height] = {
	"||||||||||||||||||||||||||||",//1
	"|............||............|",//2
	"|.||||.|||||.||.|||||.||||.|",//3
	"|.||||.|||||.||.|||||.||||.|",//4
	"|.||||.|||||.||.|||||.||||.|",//5
	"|..........................|",//6
	"|.||||.||.||||||||.||.||||.|",//7
	"|.||||.||.||||||||.||.||||.|",//8
	"|......||....||....||......|",//9
	"||||||.|||||.||.|||||.||||||",//10
	"-----|.|||||.||.|||||.|-----",//11
	"-----|.||..........||.|-----",//12
	"-----|.||.|||XX|||.||.|-----",//13
	"||||||.||.|      |.||.||||||",//14
	"P.........|      |.........P",//15
	"||||||.||.|      |.||.||||||",//16
	"-----|.||.||||||||.||.|-----",//17
	"-----|.||..........||.|-----",//18
	"-----|.||.||||||||.||.|-----",//19
	"||||||.||.||||||||.||.||||||",//20
	"|............||............|",//21
	"|.||||.|||||.||.|||||.||||.|",//22
	"|.||||.|||||.||.|||||.||||.|",//23
	"|...||................||...|",//24
	"|||.||.||.||||||||.||.||.|||",//25
	"|||.||.||.||||||||.||.||.|||",//26
	"|......||....||....||......|",//27
	"|.||||||||||.||.||||||||||.|",//28
	"|.||||||||||.||.||||||||||.|",//29
	"|..........................|",//30
	"||||||||||||||||||||||||||||",//31
};


Map::Map(int ID, borderList& border) : border(border) {
	mapID = ID;
}

// | = Wall, . = Food, Space = Empty, - = Restricted, P = Portal
CellType Map::charToCell(char c) {

	switch (c) {
	case ' ':
		return Empty;
	case '|':
		return Wall;
	case '.':
		return Food;
	case 'P':
		return Portal;
	case 'X':
		return Door;
	case 'E':
		return Enrg;
	case '-':
		return Out;
	}
	return Out;
}

char Map::cellToChar(CellType c) {

	switch (c){
	case Empty:
		return ' ';
	case Wall:
		return '|';
	case Food:
		return '.';
	case Portal:
		return 'P';
	case Door:
		return 'X';
	case Enrg:
		return 'E';
	case Out:
		return '-';
	}
	return '-';
}

//transforms position into map's coordinates with respects of arena
sf::Vector2i Map::posToTile(sf::Vector2f position) { 

	return { static_cast<int>(std::floor((position.x - border.left_pos) / tile_size)), 
			static_cast<int>(std::floor((position.y - border.up_pos ) / tile_size)) };
}

//controls cell by position with respects of arena
char Map::checkCell(sf::Vector2f position) {
	sf::Vector2i tilePos = posToTile(position);
	std::cout << tilePos.x << " , " << tilePos.y << std::endl;

	//std::cout << map2[static_cast<int>(tilePos.y)][static_cast<int>(tilePos.x)] << " ";

	if (tilePos.x > board_cell_width || tilePos.x < 0) {
		std::cout << "X DIŞINDA" << std::endl;
		return '-';
	}
	else if (tilePos.y > board_cell_height || tilePos.y < 0) {
		std::cout << "Y DIŞINDA" << std::endl;
		return '-';
	}


	return map2[tilePos.y][tilePos.x];
}

void Map::printMap() {


	for (int y = 0; y < board_cell_height; y++) { // starting from 0 and controlling by map array
		for (int x = 0; x < board_cell_width; x++) { 
			sf::RectangleShape tile;
			tile.setSize({ tile_size,tile_size });

			if (map2[y][x] == '.') {
				tile.setFillColor(sf::Color::Transparent);

			}
			else if (map2[y][x] == '|') {
				tile.setFillColor(sf::Color::White);
			}
			else {
				tile.setFillColor(sf::Color::Transparent); //for now
			}
			tile.setPosition({ (float)((x * tile_size) + border.left_pos), (float)((y * tile_size) + border.up_pos) });
			tiles.push_back(tile); // then adjusting tile to arena

		}
		std::cout << std::endl;
	}
}