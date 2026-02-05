#include "Test.h"

Test::Test() : window(
	sf::VideoMode{ 
		sf::Vector2u{500,500}
	},
	"TEST-WINDOW", 
	sf::Style::Default), sound(sound) {

	rect.setSize({ 25.f,25.f });
	rect.setPosition({ 100.f,75.f });

	if (!buffer.loadFromFile("./Sounds/start.wav")) {
		std::cout << "PROBLEM" << std::endl;
	}
	sound.setBuffer(buffer);
}

void Test::issue(sf::RectangleShape rect) {

	
	std::cout << "LOCAL BOUNDS,\nX: " << rect.getLocalBounds().size.x << "Y: " << rect.getLocalBounds().size.x << std::endl;
	std::cout << "POSITION,\nX: " << rect.getGlobalBounds().position.x << "Y: " << rect.getGlobalBounds().position.y << std::endl;
}

void Test::run() {
	issue(rect);
	sound.play();
	while (window.isOpen()) {
	}
}