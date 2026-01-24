#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window, MenuState& state ,float width) : window(window), state(state),

cursor_texture("./Sprites/cursor.png", false, sf::IntRect({0,0}, { 24, 24 })),
menu_cursor(cursor_texture),

button_size(75),
play	(window,	"Play",	{ width / 2 - button_size, 200.f }, button_size),
options	(window, "Options",	{ width / 2 - button_size, 300.f }, button_size), 
exit	(window,	"Exit",	{ width / 2 - button_size, 400.f }, button_size) {

	std::cout << "Main Menu is opened." << std::endl;

	menu_cursor.setScale({ 3,3 });
	cursor_vis = false;
}

void MainMenu::update() {
	menu_cursor.setColor(sf::Color::Transparent);

	play.text.setFillColor(sf::Color::White);
	options.text.setFillColor(sf::Color::White);
	exit.text.setFillColor(sf::Color::White);

	if (cursor_vis) {
		menu_cursor.setColor(sf::Color::Yellow);
		menu_cursor.setPosition(cursor_pos);

		cursor_vis = false;
	}

	if (play.hover()) {
		play.text.setFillColor(sf::Color::Yellow); // maybe hover func in button.cpp

		cursor_pos = { play.hitbox.getPosition().x - 70.f, play.hitbox.getPosition().y };
		cursor_vis = true;

		if (play.isClicked()) {
			state = MenuState::InGame;
		}
	}

	if (options.hover()) {
		options.text.setFillColor(sf::Color::Yellow);

		cursor_pos = { options.hitbox.getPosition().x - 70.f, options.hitbox.getPosition().y };
		cursor_vis = true;

		if (options.isClicked()) {
			//state = MenuState::MainOptions;
		}

	}

	if (exit.hover()) {
		exit.text.setFillColor(sf::Color::Yellow);

		cursor_pos = { exit.hitbox.getPosition().x - 70.f, exit.hitbox.getPosition().y };
		cursor_vis = true;

		if (exit.isClicked()) {
			state = MenuState::Exit;

		}
	}
}


void MainMenu::render() {
	window.clear(sf::Color::Black);

	window.draw(menu_cursor);


	window.draw(play.text);
	window.draw(options.text);
	window.draw(exit.text);

	//window.draw(play.hitbox);
	//window.draw(options.hitbox);
	//window.draw(exit.hitbox);

	window.display();

}