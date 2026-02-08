#include "Player.h"
#include "Map.h"


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

void Player::render() {
}