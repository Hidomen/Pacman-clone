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

