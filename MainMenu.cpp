#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window, float width) : window(window),

font("./Fonts/pacman-1.otf"), button_size(100),
play(font, "Play", button_size), options(font, "Options", button_size), exit(font, "Exit", button_size) {

	std::cout << "Main Menu is opened." << std::endl;

	//buttons.push_back(play);
	//buttons.push_back(options);
	//buttons.push_back(exit);


	//for (int i = 0; i < 3; i++) {
		//buttons[i].setFillColor(sf::Color::Blue);
		//buttons[i].setPosition({ 100.f + i, 0.f });

	//}
	play.setFillColor(sf::Color::Blue);
	options.setFillColor(sf::Color::Blue);
	exit.setFillColor(sf::Color::Blue);

	play.setPosition({ width/2 - button_size,100.f });
	options.setPosition({ width/2 - button_size,200.f });
	exit.setPosition({ width/2 - button_size,300.f });

}

void MainMenu::update() {

}

void MainMenu::render() {
	window.clear(sf::Color::Yellow);

	window.draw(play);
	window.draw(options);
	window.draw(exit);

	window.display();

}