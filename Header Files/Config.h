#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>



enum class MenuState { MainMenu, MainOptions, InGame, Pause, InGameOptions, Exit };

enum class Direction { Down, Up, Right, Left };

enum class EntityType { Player, Ghost };

//====================================
//
//  COLORS
//
//====================================
constexpr sf::Color bgColor = { 123,50,230 };

//====================================
//
//  BOARD TILE SIZE
//
//====================================
constexpr int board_cell_height = 31;
constexpr int board_cell_width = 28;

//====================================
//
//  TILE SETTINGS
//
//====================================
constexpr int tileSize = 24;
constexpr float step = tileSize / 4.f;

//====================================
//
//  WINDOW SIZE
//
//====================================
constexpr float window_width = tileSize * (board_cell_width + 4);
constexpr float window_height = tileSize * (board_cell_height + 4);
