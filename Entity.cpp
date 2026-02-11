#include "Entity.h"



Entity::Entity(Map& map, SoundManager& soundManager) : entityDirection(Direction::Left), 
map(map), soundManager(soundManager), 
sprite(texture), nextDirection(entityDirection) 
{
	
	shape.setSize({ 24,24});
}

void Entity::changeDirection(Direction new_direction) {
	if (new_direction == entityDirection) return;

	nextDirection = new_direction;
}

//should be on entity.h
void Entity::portal() {
	//out of border
	if (position.x >= map.border.right_pos  - shape.getSize().x ||
		position.x <= map.border.left_pos	+ shape.getSize().x ||
		position.y >= map.border.down_pos	+ shape.getSize().y ||
		position.y <= map.border.up_pos		+ shape.getSize().y) {

		switch (entityDirection) {
		case Direction::Down:
			shape.setPosition({ position.x, map.border.up_pos });
			break;
		case Direction::Up:
			shape.setPosition({ position.x, map.border.down_pos });
			break;
		case Direction::Right:
			shape.setPosition({ map.border.left_pos + shape.getSize().x + tileSize, position.y });
			break;
		case Direction::Left:
			shape.setPosition({ map.border.right_pos - shape.getSize().x, position.y });
			break;
		}

	}

}

//only when on grid, and check if its player
void Entity::pellet() {

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

void Entity::checkRotation() {
	sf::Vector2f nextPos;

	switch (nextDirection) {

	case Direction::Down:
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
void Entity::applyMovement() {

	shape.setPosition(position);

	//if on grid
	if (map.isOnGrid(position)) {
		//portal();

		if (EntityType::Player == entityType) {
			pellet();
		}

		switch (entityDirection) {

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
		} //check next wall collision -> return
		if (Wall == map.checkCellbyPos(targetPosition)) {
			return;
		}

		
		
	}

	//in game
	
	position = nextStep;

	//portal();
}

void Entity::computeNextPosition() {
	nextStep = position;
	shape.setPosition(position);

	if (map.isOnGrid(position)) {
		checkRotation();
	}

	switch (entityDirection) {

	case Direction::Down:
		nextStep = { position.x, position.y + step };
		break;
	case Direction::Up:
		nextStep = { position.x, position.y - step };
		break;
	case Direction::Right:
		nextStep = { position.x + step, position.y };
		break;
	case Direction::Left:
		nextStep = { position.x - step, position.y };
		break;
	}
}