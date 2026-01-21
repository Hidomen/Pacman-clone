#pragma once

#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "Map.h"


class Player : public gameObject {
public:

	Player(Map& map, borderList& border);

	int FoodCount;

	void update();
};

