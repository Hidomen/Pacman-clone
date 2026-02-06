#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window, MenuState& state ,float width) : window(window), state(state),
backgroundTexture("./Sprites/main-screen-BG.jpeg", false, sf::IntRect({1024,1056}, {0,0})),	//dont construct here
cursorTexture("./Sprites/cursor.png", false, sf::IntRect({0,0}, { 24, 24 })),			//dont construct here
cursor(cursorTexture), background(backgroundTexture),

button_size(75),
play	(window,	"Play",	{ width / 2 - button_size, 200.f }, button_size),
options	(window, "Options",	{ width / 2 - button_size, 300.f }, button_size), 
exit	(window,	"Exit",	{ width / 2 - button_size, 400.f }, button_size) {

	std::cout << "Main Menu is opened." << std::endl;

	cursor.setScale({ 3,3 });
	cursorVis = false;

	//background.setPosition({ 0,0 });
	background.setScale({ static_cast<float>(window.getSize().x) / 1024, static_cast<float>(window.getSize().y) / 1056 });
	
}

void MainMenu::update() {
	cursor.setColor(sf::Color::Transparent);

	play.text.setFillColor(sf::Color::Red);
	options.text.setFillColor(sf::Color::Green);
	exit.text.setFillColor(bgColor);

	if (cursorVis) {
		cursor.setColor(sf::Color::Yellow);
		cursor.setPosition(cursorPos);

		cursorVis = false;
	}

	if (play.hover()) {
		play.text.setFillColor(sf::Color::Yellow); // maybe hover func in button.cpp

		cursorPos = { play.hitbox.getPosition().x - 70.f, play.hitbox.getPosition().y };
		cursorVis = true;

		if (play.isClicked()) {
			state = MenuState::InGame;
			
		}
	}

	if (options.hover()) {
		options.text.setFillColor(sf::Color::Yellow);

		cursorPos = { options.hitbox.getPosition().x - 70.f, options.hitbox.getPosition().y };
		cursorVis = true;

		if (options.isClicked()) {
			//state = MenuState::MainOptions;
		}

	}

	if (exit.hover()) {
		exit.text.setFillColor(sf::Color::Yellow);

		cursorPos = { exit.hitbox.getPosition().x - 70.f, exit.hitbox.getPosition().y };
		cursorVis = true;

		if (exit.isClicked()) {
			state = MenuState::Exit;

		}
	}
}


void MainMenu::render() {
	window.clear(sf::Color::Black);
	window.draw(background);

	window.draw(cursor);


	window.draw(play.text);
	window.draw(options.text);
	window.draw(exit.text);

	//window.draw(play.hitbox);
	//window.draw(options.hitbox);
	//window.draw(exit.hitbox);

	window.display();

}