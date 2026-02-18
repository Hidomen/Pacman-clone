#include "Button.h"


Button::Button(sf::RenderWindow& window, sf::Font& font, std::string inputText, sf::Vector2f position, int textSize) : window(window), font(font),
text(font, inputText, textSize)

{
	text.setFillColor(sf::Color::White);
	text.setPosition(position);
	
	hitbox.setSize({ static_cast<float>((textSize / 2.f) * inputText.length()), static_cast<float>(textSize * 1.f) });

	hitbox.setPosition({position.x, position.y + 10}); //ortala

	//for debugging
	
	hitbox.setFillColor(sf::Color::Transparent);
	//hitbox.setOutlineThickness(5.f);
	//hitbox.setOutlineColor(sf::Color::Green);
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
