#include "Player.h"
#include "Map.h"

Player::Player(Map& map, SoundManager& soundManager) : Entity(map, soundManager), nextDirection(entityDirection), Psprite(Ptexture) {
	//rectangle_init(player, sf::Vector2f{ width, height }, sf::Vector2f{ grid_size, grid_size });
	
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Green);
	shape.setOutlineThickness(2.f);
	
	score = 0;
	health = 3;

	if ( Ptexture.loadFromFile("./Sprites/cursor.png", false, sf::IntRect({ 12,12 }, { 12,12 })) ) {
		Psprite.setScale({ 2.f,2.f});
		std::cout << "TEXTURE ADDED" << std::endl;
		Psprite.setTexture(texture);
		Psprite.setColor(sf::Color::Yellow);
	}
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
			shape.setPosition({ map.border.left_pos + shape.getSize().x + tileSize, position.y});
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

	//pellet eaten
	if (Pellet == map.checkCellbyPos(position)) {
		map.pelletEaten(tilePos);

		soundManager.isEating = true;
		//add up to score
		score += 10;
		std::cout << score << std::endl;
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
	Psprite.setPosition(position);
}