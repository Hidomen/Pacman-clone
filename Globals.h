#pragma once

enum class MenuState { MainMenu, MainOptions, InGame, Pause, InGameOptions, Exit };

enum class Direction { Down, Up, Right, Left };

constexpr int tileSize = 24;
static float step = tileSize / 4.f;