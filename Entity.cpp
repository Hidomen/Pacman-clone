#include "Entity.h"



Entity::Entity(Map& map, SoundManager& soundManager) : entityDirection(Direction::Left), map(map), soundManager(soundManager), sprite(texture) {
	shape.setSize({ 24,24});

	if (texture.loadFromFile("./Sprites/cursor.png", false, sf::IntRect({ 12,12 }, { 12,12 }))) {
		sprite.setScale({ 2.f,2.f });
		std::cout << "TEXTURE ADDED" << std::endl;
		sprite.setTexture(texture);
		sprite.setColor(sf::Color::Yellow);
	}
}




//void Entity::move(){}