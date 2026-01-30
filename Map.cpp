#include "Map.h"
#include <iostream>

//std::array <std::string, board_cell_height> map2 = {
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
	"||||||.||||| || |||||.||||||",//10
	"     |.||||| || |||||.|     ",//11
	"     |.||          ||.|     ",//12
	"     |.|| |||XX||| ||.|     ",//13
	"||||||.|| |      | ||.||||||",//14
	"P     .   |      |   .     P",//15
	"||||||.|| |      | ||.||||||",//16
	"     |.|| |||||||| ||.|     ",//17
	"     |.||          ||.|     ",//18
	"     |.|| |||||||| ||.|     ",//19
	"||||||.|| |||||||| ||.||||||",//20
	"|............||............|",//21
	"|.||||.|||||.||.|||||.||||.|",//22
	"|.||||.|||||.||.|||||.||||.|",//23
	"|...||.......  .......||...|",//24
	"|||.||.||.||||||||.||.||.|||",//25
	"|||.||.||.||||||||.||.||.|||",//26
	"|......||....||....||......|",//27
	"|.||||||||||.||.||||||||||.|",//28
	"|.||||||||||.||.||||||||||.|",//29
	"|..........................|",//30
	"||||||||||||||||||||||||||||",//31
};


Map::Map(int ID, borderList& border) : border(border),
pelletTexture	("./Sprites/pellet.png", false, sf::IntRect({24,24}, {0,0})),
  wallTexture	(sf::Vector2u({24,24}),  false),
 emptyTexture	("./Sprites/empty.png",  false, sf::IntRect({24,24}, {0,0}))

{
	mapID = ID;

	//spriteMap.resize(board_cell_height, std::vector<sf::Sprite>(board_cell_width));
}

// | = Wall, . = Food, Space = Empty, - = Restricted, P = Portal
CellType Map::charToCell(char c) {

	switch (c) {
	case ' ':
		return Empty;
	case '|':
		return Wall;
	case '.':
		return Pellet;
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
	case Pellet:
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

	//std::cout << tilePos.x << " , " << tilePos.y << std::endl;

	//std::cout << map2[static_cast<int>(tilePos.y)][static_cast<int>(tilePos.x)] << " ";

	//outside of x
	if (tilePos.x > board_cell_width || tilePos.x < 0) {
		return 'P';
	}
	//outside of y
	else if (tilePos.y > board_cell_height || tilePos.y < 0) {
		return 'P';
	}

	return charToCell(map2[tilePos.y][tilePos.x]);
}


CellType Map::positionToTile(sf::Vector2f position) {
	sf::Vector2i tilePos = posToTile(position);

	sf::Sprite tile = tileVector[tilePos.y * 29 + tilePos.x];
	if (checkCell({ tile.getPosition().x, tile.getPosition().x }) == Pellet) {
		std::cout << "PELLEETTTTT" << std::endl;
	}

	return Wall;
}

//based on neighbors
void Map::wallTexturer(sf::Vector2i tilePos) {
	wallTexture.loadFromFile("./Sprites/wall-vertical.png");
	return;

	if (tilePos.y - 1 > 0 && tilePos.y + 1 < board_cell_height) {
		//return;
		//problem is in this if
		if (cellToChar(Wall) == map2[tilePos.y - 1][tilePos.x] && cellToChar(Wall) == map2[tilePos.y + 1][tilePos.x]) {
			wallTexture.loadFromFile("./Sprites/wall-vertical.png");
			return;

		}
		return;

	}
	else {
		wallTexture.loadFromFile("./Sprites/wall-horizontal.png");
		return;
	}
	return;
}

void Map::load() {

	sf::Sprite tile(wallTexture);

	for (int y = 0; y < board_cell_height; y++) { // starting from 0 and controlling by map array
		for (int x = 0; x < board_cell_width; x++) { 
			//tile.setSize({ tile_size,tile_size });

			if (map2[y][x] == cellToChar(Pellet)) {
				//add to another vector
				tile.setTexture(pelletTexture);

			}
			else if (map2[y][x] == cellToChar(Wall)) {

				wallTexturer({y,x});
				tile.setTexture(wallTexture);	
			} 
			else {
				//tile.setFillColor(sf::Color::Transparent); //for now
				tile.setTexture(emptyTexture);
			}
			tile.setPosition({ (float)((x * tile_size) + border.left_pos), (float)((y * tile_size) + border.up_pos) });
			tileVector.push_back(tile); // then adjusting tile to arena

		}
	}
}