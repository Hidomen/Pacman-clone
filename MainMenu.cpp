#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window, MenuState& state ,float width) : window(window), state(state),

font("./Fonts/pacman-1.otf"), button_size(100),
play("Play", { width / 2 - button_size,100.f }, button_size),
options("Options", { width / 2 - button_size,300.f }, button_size), 
exit("Exit", { width / 2 - button_size,500.f }, button_size) {

	std::cout << "Main Menu is opened." << std::endl;

	//buttons.push_back(play);
	//buttons.push_back(options);
	//buttons.push_back(exit);


	//for (int i = 0; i < 3; i++) {
		//buttons[i].setFillColor(sf::Color::Blue);
		//buttons[i].setPosition({ 100.f + i, 0.f });

	//}
}

void MainMenu::update() {

	if (play.update(window)) {
		state = sInGame;
	}

	//if (options.update(window)) {

	//}

	//if (exit.update(window)) {

	//}
		options.update(window);
		exit.update(window);
}

void MainMenu::render() {
	window.clear(sf::Color::Yellow);

	window.draw(play.text);
	window.draw(options.text);
	window.draw(exit.text);

	window.draw(play.hitbox);
	window.draw(options.hitbox);
	window.draw(exit.hitbox);

	window.display();

}