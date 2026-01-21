#pragma once

#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "Map.h"


class Player : public gameObject {
public:

	Player(Map& map);

	int FoodCount;

	void update();
};

