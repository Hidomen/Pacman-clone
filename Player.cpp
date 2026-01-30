#include "Player.h"
#include "Map.h"

Player::Player(Map& map) : gameObject(map) {
	//rectangle_init(player, sf::Vector2f{ width, height }, sf::Vector2f{ grid_size, grid_size });
	
	Player::shape.setFillColor(sf::Color::Yellow);

	

	Player::pelletCount = 0;
	score = 0;

	texture.loadFromFile("Sprites/Pacman.png", false, sf::IntRect({0,0},{24,24}));
	//texture.update()
	sprite.setTexture(texture);

	
}

void Player::checkCollision() {
	sf::Vector2i tile = map.posToTile(position);

	if (Wall == map.checkCell(position)) {
		return;
	}
	if (Pellet == map.checkCell(position)) {
		//first control if its already eaten, make it clear and give point
	}
	if (Portal == map.checkCell(position)) {
		if (Direction::Left == objectDirection) {
			shape.setPosition({static_cast<float>((tile.x + board_cell_width) * tile_size), position.y});
		}
		else if (Direction::Right == objectDirection) {
			shape.setPosition({static_cast<float>((tile.x - board_cell_width + 4) * tile_size), position.y });
		}
	}

}

void Player::move() {

	//std::cout << "LEFT BORDER: " << map.border.left_pos << " RIGHT BORDER:"	<< map.border.right_pos << std::endl;
	//std::cout << "UP BORDER: "	 << map.border.up_pos << " DOWN BORDER: "	<< map.border.down_pos << std::endl;

	//std::cout << "NEXT DIR: " << next_direction << "   OBJ. DIR: " << object_direction << std::endl;

	checkRotation();

	switch (objectDirection) {

	case Direction::Down:
		//position is based by top-left corner of shape
		if (Wall == map.checkCell({ position.x, position.y + shape.getSize().y + step })) return;
		shape.move({ 0, step });
		break;

	case Direction::Up:
		if (Wall == map.checkCell({ position.x,position.y - step })) return;
		shape.move({ 0, -step });
		break;

	case Direction::Right:
		if (Wall == map.checkCell({ position.x + shape.getSize().x + step , position.y })) return;
		shape.move({ step, 0 });
		break;

	case Direction::Left:
		if (Wall == map.checkCell({ position.x - step , position.y })) return;
		shape.move({ -step, 0 });
		break;

	}

	checkCollision();
	position = shape.getPosition();

	//std::cout << "MOVED POS: " << position.x << ", " << position.y << std::endl;
}