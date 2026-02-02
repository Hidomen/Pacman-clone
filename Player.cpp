#include "Player.h"
#include "Map.h"

Player::Player(Map& map) : Entity(map), nextDirection(entityDirection) {
	//rectangle_init(player, sf::Vector2f{ width, height }, sf::Vector2f{ grid_size, grid_size });
	
	Player::shape.setFillColor(sf::Color::Yellow);

	

	Player::pelletCount = 0;
	score = 0;

	texture.loadFromFile("Sprites/Pacman.png", false, sf::IntRect({0,0},{24,24}));
	//texture.update()
	sprite.setTexture(texture);

	
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
		position.y >= map.border.down_pos  - shape.getSize().y ||
		position.y <= map.border.up_pos	   + shape.getSize().y ) {

		switch (entityDirection){
		case Direction::Down:
			shape.setPosition({position.x, map.border.up_pos});
			break;
		case Direction::Up:
			shape.setPosition({ position.x, map.border.down_pos });
			break;
		case Direction::Right:
			shape.setPosition({ map.border.left_pos + shape.getSize().x, position.y});
			break;
		case Direction::Left:
			shape.setPosition({ map.border.right_pos, position.y });
			break;
		}

	}

}

//only when on grid
void Player::pellet() {
	//if()
	sf::Vector2i tilePos = map.posToTile(position);
	sf::Sprite cell = map.tileVector[tilePos.y * board_cell_width + tilePos.x];

	if (Pellet == map.checkCellbyPos(position)) {
		map.tileVector[tilePos.y * board_cell_width + tilePos.x].setTexture(map.emptyTexture); //then change array element
		map.pelletEaten(tilePos);
		//add up to score
		score += 10;
		std::cout << score << std::endl;
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

//sf::Sprite nextCell = map.tileVector[position.y * board_cell_width + position.x];


//for every frame of moveme

void Player::move() {
	//portal();
	//if on grid
	if (map.isOnGrid(position)) {
		//check rotation
		pellet();
		checkRotation();

		//check next wall collision -> return
		sf::Vector2f nextPosForCollision;

		switch (entityDirection){

		case Direction::Down: // change x and y
			nextPosForCollision = { position.x, position.y + tileSize };
			break;
		case Direction::Up:
			nextPosForCollision = { position.x, position.y - tileSize };
			break;
		case Direction::Right:
			nextPosForCollision = { position.x + tileSize, position.y };
			break;
		case Direction::Left:
			nextPosForCollision = { position.x - tileSize, position.y };
			break;
		}
		if (Wall == map.checkCellbyPos(nextPosForCollision)) {
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
}