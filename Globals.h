#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum class MenuState { MainMenu, MainOptions, InGame, Pause, InGameOptions, Exit };

enum class Direction { Down, Up, Right, Left };

constexpr int tileSize = 24;
static float step = tileSize / 3.f;

constexpr sf::Color bgColor = { 123,50,230 };
