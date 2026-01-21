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

//CellType map1[board_cell_width][board_cell_height] = { //28,31
//	{Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall},
//	{Wall,Food,Food,Food,Food,Food,Food,Food,Food,Food,Food,Food,Food,Wall,Wall,Food,Food,Food,Food,Food,Food,Food,Food,Food,Food,Food,Food,Wall},
//};

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

void Map::printID() {
	std::cout << mapID;
}


//transforms position into map's coordinates with respects of arena
sf::Vector2f Map::posToTile(sf::Vector2f position) { 

	return { ((position.x - border.left_pos) / grid_size), ((position.y - border.up_pos ) / grid_size) };
}

//controls cell by position with respects of arena
char Map::checkCell(sf::Vector2f position) {
	sf::Vector2f tilePos = posToTile(position);

	std::cout << map2[static_cast<int>(tilePos.y)][static_cast<int>(tilePos.x)] << " ";

	if (tilePos.x > board_cell_width || tilePos.x < 0) {
		std::cout << "X DIŞINDA" << std::endl;
		return '-';
	}
	else if (tilePos.y > board_cell_height || tilePos.y < 0) {
		std::cout << "Y DIŞINDA" << std::endl;
		return '-';
	}


	return map2[static_cast<int>(tilePos.y)][static_cast<int>(tilePos.x)];
}

void Map::printMap() {


	for (int y = 0; y < board_cell_height; y++) { // starting from 0 and controlling by map array
		for (int x = 0; x < board_cell_width; x++) { 
			sf::RectangleShape tile;
			tile.setSize({ grid_size,grid_size });

			if (map2[y][x] == '.') {
				tile.setFillColor(sf::Color::Transparent);

			}
			else if (map2[y][x] == '|') {
				tile.setFillColor(sf::Color::White);
			}
			else {
				tile.setFillColor(sf::Color::Red);
			}
			tile.setPosition({ (float)((x * grid_size) + border.left_pos), (float)((y * grid_size) + border.up_pos) });
			tiles.push_back(tile); // then adjusting tile to arena

		}
		std::cout << std::endl;
	}
}