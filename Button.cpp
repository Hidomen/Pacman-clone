#include "Button.h"


Button::Button(std::string inputText, sf::Vector2f position, int button_size) :
font("./Fonts/pacman-1.otf"), 
text_size(button_size * 0.75f), text(font, inputText, text_size), 
hitbox({ text.getGlobalBounds().size.x + 20.f , static_cast<float>(button_size)}) { //get rid of magic numbers

	text.setFillColor(sf::Color::Blue);

	text.setPosition(position);
	

	std::cout << text.getCharacterSize() << std::endl;
	
	hitbox.setPosition({position.x - 10.f, position.y}); //ortala
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(5.f);
	hitbox.setOutlineColor(sf::Color::Green);
}

bool Button::update(sf::RenderWindow& window) {
	sf::Vector2i mousePosi = sf::Mouse::getPosition(window);

	//mouse in hitbox
	if (hitbox.getGlobalBounds().contains(sf::Vector2f(mousePosi))) {
		hitbox.setFillColor(sf::Color::Red);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			std::cout << "PRESSED" << std::endl;
			return true;
		}
	} //mouse is outside
	else {
		hitbox.setFillColor(sf::Color::Transparent);
	}

	return false;
}
