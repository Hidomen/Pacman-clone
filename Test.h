#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

class Test
{
public:
	sf::RenderWindow window;
	Test();

	sf::RectangleShape rect;
	sf::Music music;

	sf::Sound sound;
	sf::SoundBuffer buffer;

	void run();
	void issue(sf::RectangleShape rect);
};

