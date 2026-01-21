#include "Player.h"
#include "Map.h"

Player::Player(Map& map) : gameObject(map) {
	//rectangle_init(player, sf::Vector2f{ width, height }, sf::Vector2f{ grid_size, grid_size });
	
	Player::shape.setSize({grid_size,grid_size});
	Player::shape.setFillColor(sf::Color::Yellow);

	Player::position = { 240, 240 };
	Player::shape.setPosition(position);

	Player::FoodCount = 0;
}

