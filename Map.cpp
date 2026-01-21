#include "Map.h"
#include <iostream>

Map::Map(int ID) {
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
}

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

void Map::printID() {
	std::cout << mapID;
}

sf::Vector2i Map::posToTile(sf::Vector2f position) {

	return { (int)position.x / grid_size, (int)position.y / grid_size };
}

char Map::checkCell(sf::Vector2f position) {
	sf::Vector2i tilePos = posToTile(position);

	std::string vertical = map2[tilePos.y];

	return vertical[tilePos.x];
}