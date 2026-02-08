#include "Player.h"
#include "Map.h"


//window added for just debug
Player::Player(Map& map, SoundManager& soundManager, sf::RenderWindow& window) : window(window), Entity(map, soundManager), nextDirection(entityDirection)
{
	//rectangle_init(player, sf::Vector2f{ width, height }, sf::Vector2f{ grid_size, grid_size });
	
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Green);
	shape.setOutlineThickness(2.f);
	
	score = 0;
	health = 3;

}

void Player::changeDirection(Direction new_direction) {
	if (new_direction == entityDirection) return;

	nextDirection = new_direction;
	//update sprite //

}

//should be on entity.h
void Player::portal() {
	//out of border
	if (position.x >= map.border.right_pos - shape.getSize().x ||
		position.x <= map.border.left_pos  + shape.getSize().x ||
		position.y >= map.border.down_pos  + shape.getSize().y ||
		position.y <= map.border.up_pos	   + shape.getSize().y ) {

		switch (entityDirection){
		case Direction::Down:
			shape.setPosition({position.x, map.border.up_pos});
			break;
		case Direction::Up:
			shape.setPosition({ position.x, map.border.down_pos });
			break;
		case Direction::Right:
			shape.setPosition({ map.border.left_pos + shape.getSize().x + tileSize, position.y});
			break;
		case Direction::Left:
			shape.setPosition({ map.border.right_pos - shape.getSize().x, position.y });
			break;
		}

	}

}

//only when on grid
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

void Player::checkRotation(){
	sf::Vector2f nextPos;

	switch (nextDirection) {

	case Direction::Down: // change x and y
		nextPos = { position.x, position.y + tileSize };
		break;
	case Direction::Up:
		nextPos = { position.x, position.y - tileSize };
		break;
	case Direction::Right:
		nextPos = { position.x + tileSize, position.y };
		break;
	case Direction::Left:
		nextPos = { position.x - tileSize, position.y };
		break;
	}

	if (Wall != map.checkCellbyPos(nextPos)) {
		entityDirection = nextDirection;
	}
}


//for every frame of movement
void Player::move() {

	//if on grid
	if (map.isOnGrid(position)) {
		//portal();

		pellet();
		checkRotation();

		//check next wall collision -> return

		switch (entityDirection){

		case Direction::Down: // change x and y
			targetPosition = { position.x, position.y + tileSize };
			break;
		case Direction::Up:
			targetPosition = { position.x, position.y - tileSize };
			break;
		case Direction::Right:
			targetPosition = { position.x + tileSize, position.y };
			break;
		case Direction::Left:
			targetPosition = { position.x - tileSize, position.y };
			break;
		}
		if (Wall == map.checkCellbyPos(targetPosition)) {
			return;
		}
	}

	switch (entityDirection){

	case Direction::Down:
		//shape.setPosition({ position.x, position.y + step });
		shape.move({ 0, step });
		break;
	case Direction::Up:
		shape.move({ 0, -step });
		break;
	case Direction::Right:
		shape.move({ step, 0 });
		break;
	case Direction::Left:
		shape.move({ -step, 0 });
		break;
	}

	//portal();

	position = shape.getPosition();
	//Psprite.setPosition(position);
}

void Player::update() {
	
}

void Player::render() {
}