#include "../Header Files/MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window, MenuState& state, sf::Font& font) : window(window), state(state), font(font),

backgroundTexture("./Assets/Sprites/main-screen-BG.jpeg", false, sf::IntRect({1024,1056}, {0,0})),	//dont construct here
cursorTexture("./Assets/Sprites/cursor.png", false, sf::IntRect({0,0}, { 24, 24 })),		//dont construct here

cursor(cursorTexture), background(backgroundTexture),

textSize(75),
play	(window, font,	"Play",		{ static_cast<float>(window.getSize().x / 2 - textSize), 200.f }, textSize),
options	(window, font,	"Options",	{ static_cast<float>(window.getSize().x / 2 - textSize), 300.f }, textSize),
exit	(window, font,	"Exit",		{ static_cast<float>(window.getSize().x / 2 - textSize), 400.f }, textSize) {

	std::cout << "Main Menu is opened." << std::endl;

	cursor.setScale({ 3,3 });
	cursorVis = false;

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

	//connect them and check in one loop
	if (play.hover()) {
		play.text.setFillColor(sf::Color::Yellow); // maybe hover func in button.cpp

		cursorPos = { play.hitbox.getPosition().x - cursor.getGlobalBounds().size.x, 
					  play.hitbox.getPosition().y + ( play.text.getCharacterSize() - cursor.getGlobalBounds().size.y)  / 2};

		cursorVis = true;

		if (play.isClicked()) {
			state = MenuState::InGame;
			
		}
	}

	if (options.hover()) {
		options.text.setFillColor(sf::Color::Yellow);

		cursorPos = { options.hitbox.getPosition().x - cursor.getGlobalBounds().size.x,
					  options.hitbox.getPosition().y + ( options.text.getCharacterSize() - cursor.getGlobalBounds().size.y ) / 2 };
		cursorVis = true;

		if (options.isClicked()) {
			//state = MenuState::MainOptions;
		}

	}

	if (exit.hover()) {
		exit.text.setFillColor(sf::Color::Yellow);

		cursorPos = { exit.hitbox.getPosition().x - cursor.getGlobalBounds().size.x, 
					  exit.hitbox.getPosition().y + ( exit.text.getCharacterSize() - cursor.getGlobalBounds().size.y ) / 2};
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

	window.draw(play.hitbox);
	window.draw(options.hitbox);
	window.draw(exit.hitbox);

	window.display();
}