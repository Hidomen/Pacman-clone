#include "Player.h"
#include "Map.h"

Player::Player(Map& map) : gameObject(map) {
	//rectangle_init(player, sf::Vector2f{ width, height }, sf::Vector2f{ grid_size, grid_size });
	
	Player::shape.setSize({tileSize,tileSize});
	Player::shape.setFillColor(sf::Color::Yellow);

	Player::position = { 24*8, 24*4 };
	Player::shape.setPosition(sf::Vector2f(position));

	Player::FoodCount = 0;
}

