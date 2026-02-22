#include "../Header Files/Map.h"
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
pelletTexture	("./Assets/Sprites/pellet.png", false, sf::IntRect({tileSize, tileSize}, {0,0})),
  vWallTexture	("./Assets/Sprites/wall-vertical.png",  false, sf::IntRect({tileSize, tileSize}, {0,0})),
  hWallTexture  ("./Assets/Sprites/wall-horizontal.png",  false, sf::IntRect({tileSize, tileSize}, {0,0})),
  cWallTexture ("./Assets/Sprites/wall-corner.png", false, sf::IntRect({tileSize, tileSize}, {0,0})),
 emptyTexture	("./Assets/Sprites/empty.png",  false, sf::IntRect({tileSize, tileSize}, {0,0})),
  testTexture	("./Assets/Sprites/wall.png",   false, sf::IntRect({tileSize, tileSize}, {0,0}))
	  

{
	mapID = ID;
	remainingPellet = 0;
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

	return { static_cast<int>(std::floor((position.x - border.left_pos) / tileSize)), 
			static_cast<int>(std::floor((position.y - border.up_pos ) / tileSize)) };
}

CellType Map::checkCellbyTile(sf::Vector2i tile) {

	if (tile.x > board_cell_width) return Out;
	if (tile.x < 0) return Out;

	if (tile.y > board_cell_height) return Out;
	if (tile.y < 0) return Out;

	return charToCell(loadedMap[tile.y][tile.x]);
}


//controls cell by position with respects of arena
CellType Map::checkCellbyPos(sf::Vector2f position) {
	sf::Vector2i tilePos = posToTile(position);

	return checkCellbyTile(tilePos);
}



//based on neighbors
void Map::wallTexturer(sf::Vector2i tilePos, sf::Sprite& tile) {
	//set statements from least condition to more

	if (Wall == checkCellbyTile({ tilePos.x, tilePos.y - 1 }) && Wall == checkCellbyTile({ tilePos.x, tilePos.y + 1 })) {


		tile.setTexture(vWallTexture);
	}
	else if (Wall == checkCellbyTile({ tilePos.x - 1, tilePos.y }) && Wall == checkCellbyTile({ tilePos.x + 1, tilePos.y })) {

		tile.setTexture(hWallTexture);
	}
	else {
		tile.setTexture(cWallTexture);
	}

	if (Wall == checkCellbyTile({ tilePos.x, tilePos.y + 1 }) &&
		Wall == checkCellbyTile({ tilePos.x, tilePos.y - 1 }) &&
		Wall == checkCellbyTile({ tilePos.x + 1, tilePos.y }) &&
		Wall == checkCellbyTile({ tilePos.x - 1, tilePos.y }))
	{
		tile.setTexture(emptyTexture);
	}

}

void Map::load() {
	remainingPellet = 0;
	sf::Sprite tile(emptyTexture);


	for (int i = 0; i < board_cell_height; i++) {
		loadedMap[i] = map2[i];
	}

	for (int y = 0; y < board_cell_height; y++) { // starting from 0 and controlling by map array
		for (int x = 0; x < board_cell_width; x++) { 
			//tile.setSize({ tile_size,tile_size });

			if (loadedMap[y][x] == cellToChar(Pellet)) {
				//add to another vector
				tile.setTexture(pelletTexture);
				remainingPellet++;

			}
			else if (loadedMap[y][x] == cellToChar(Wall)) {

				wallTexturer({x,y}, tile);
				//tile.setTexture(wallTexture);	
			} 
			else {
				//tile.setFillColor(sf::Color::Transparent); //for now
				tile.setTexture(emptyTexture);
			}
			tile.setPosition({ (float)((x * tileSize) + border.left_pos), (float)((y * tileSize) + border.up_pos) });
			tileVector.push_back(tile); // then adjusting tile to arena

		}
	}
}

bool Map::isOnGrid(sf::Vector2f position) {
	float checkGridX = (position.x - border.left_pos) / 24.f;
	float checkGridY = (position.y - border.up_pos) / 24.f;

	if (checkGridX == std::floor(checkGridX) && checkGridY == std::floor(checkGridY)) {
		return true;
	}
	return false;
}

void Map::pelletEaten(sf::Vector2i tile) {
	//change texture
	tileVector[tile.y * board_cell_width + tile.x].setTexture(emptyTexture); 
	//then change array element
	loadedMap[tile.y][tile.x] = ' ';
	remainingPellet--;
}

void Map::clear() {

}