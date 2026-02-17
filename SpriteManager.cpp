#include "SpriteManager.h"

SpriteManager::SpriteManager(sf::RenderWindow& window, EntityType entityType) : sprite(texture), window(window) {
	

	switch (entityType){
		 
	case EntityType::Player:

		if (!texture.loadFromFile("./Sprites/cursor.png")) {
			std::cout << "[SpriteManager] - player texture couldn't load" << std::endl;
			return;
		}
		break;
	
	case EntityType::Ghost:
		break;
	}

	sprite.setTexture(texture);
}

void SpriteManager::rotate(Direction direction) {
	
	switch (direction){

	case Direction::Down:
		break;
	case Direction::Up:
		break;
	case Direction::Right:
		break;
	case Direction::Left:
		break;
	
	}

	sprite.rotate(sf::degrees(90));
}

void SpriteManager::render() {
	window.draw(sprite);
}