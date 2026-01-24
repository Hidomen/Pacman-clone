#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Button.h"



class MainMenu
{
public:
	sf::RenderWindow& window;
	MenuState& state;
	MainMenu(sf::RenderWindow& window, MenuState& state, float width);


	int button_size;

	sf::Font font; //

	sf::Texture cursor_texture;
	sf::Sprite menu_cursor;
	sf::Vector2f cursor_pos;
	bool cursor_vis;

	Button play;
	Button options;
	Button exit;
	

	//std::vector<sf::Text> buttons;
	//
	
	void update();
	void render();
};

