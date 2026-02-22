#include "../Header Files/Player.h"
#include "../Header Files/Map.h"


//window added for just debug
Player::Player(Map& map, SoundManager& soundManager, sf::RenderWindow& window) : window(window), Entity(map, soundManager)
{
	//rectangle_init(player, sf::Vector2f{ width, height }, sf::Vector2f{ grid_size, grid_size });
	
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Green);
	shape.setOutlineThickness(2.f);
	
	score = 0;
	health = 3;

	entityType = EntityType::Player;
}

void Player::update() {
	
}

//only when on grid, and check if its player
void Player::pellet() {

	sf::Vector2i tilePos = map.posToTile(position);
	sf::Sprite cell = map.tileVector[tilePos.y * board_cell_width + tilePos.x];

	//pellet eaten
	if (Pellet == map.checkCellbyPos(position)) {
		map.pelletEaten(tilePos);

		soundManager.isEating = true;
		//add up to score
		score += 10;
	}
	else {
		soundManager.isEating = false;
	}
}

void Player::render() {
}