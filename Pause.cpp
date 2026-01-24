#include "Pause.h"

Pause::Pause(sf::RenderWindow& window) : window(window), 
options(window, "Options", {200.f,200.f}, 100), mainMenu(window, "Return to main menu", {400.f,200.f}, 100) {

	options.text.setFillColor(sf::Color::White);
	mainMenu.text.setFillColor(sf::Color::White);
}


void Pause::update() {

}

void Pause::render() {
	window.draw(options.text);
	window.draw(options.hitbox);

	window.draw(mainMenu.text);
	window.draw(mainMenu.hitbox);
}