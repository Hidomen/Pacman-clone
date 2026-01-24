#include "Button.h"


Button::Button(sf::RenderWindow& window, std::string inputText, sf::Vector2f position, int button_size) : window(window),
font("./Fonts/alagard.ttf"), 
text_size(button_size * 0.75f), text(font, inputText, text_size), 
hitbox({ text.getGlobalBounds().size.x + 20.f , static_cast<float>(button_size)}) { //get rid of magic numbers

	text.setFillColor(sf::Color::White);

	text.setPosition(position);
	
	std::cout << text.getCharacterSize() << std::endl;
	
	hitbox.setPosition({position.x - 10.f, position.y}); //ortala
	hitbox.setFillColor(sf::Color::Transparent);

	hitbox.setOutlineThickness(5.f);
	hitbox.setOutlineColor(sf::Color::Green);
}

bool Button::hover() {
	sf::Vector2i mousePosi = sf::Mouse::getPosition(window);


	if (hitbox.getGlobalBounds().contains(sf::Vector2f(mousePosi))) {
		return true;
	}
	return false;
}

bool Button::isClicked() {

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		return true;
	}
	return false;
}
