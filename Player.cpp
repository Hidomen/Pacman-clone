#include "Player.h"
#include "Map.h"

Player::Player(Map& map, sf::RectangleShape& arena) : gameObject(map, arena) {
	//rectangle_init(player, sf::Vector2f{ width, height }, sf::Vector2f{ grid_size, grid_size });
	
	Player::shape.setSize({grid_size,grid_size});
	Player::shape.setFillColor(sf::Color::Yellow);

	Player::position = { 0, 0 };
	Player::shape.setPosition(position);

	Player::FoodCount = 0;
}

