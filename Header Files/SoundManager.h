#pragma once
#include <SFML/Audio.hpp>
#include "Config.h"

class SoundManager{
private:

	sf::SoundBuffer startBuffer;
	sf::SoundBuffer intermissionBuffer;
	
	sf::SoundBuffer ghostMoveBuffer;
	sf::SoundBuffer ghostRetreatBuffer;
	
	sf::SoundBuffer pacmanMoveBuffer;
	sf::SoundBuffer pacmanEatBuffer;
	sf::SoundBuffer pacmanFruitBuffer;
	sf::SoundBuffer pacmanInvincibleBuffer;

	sf::Music menuTheme;

	sf::Sound start;
	sf::Sound intermission;
	sf::Sound ghostMove;
	sf::Sound ghostRetreat;
	sf::Sound pacmanMove;
	sf::Sound pacmanEat;
	sf::Sound pacmanFruit;
	sf::Sound pacmanInvincible;

	sf::Time pacmanEat_playTime;
	sf::Time pacmanEat_durationTime;

public:
	SoundManager();

	bool isEating;
	float startDuration;

	void stopAll();
	void pauseAll();

	void statePlay(MenuState state);
	void generalPlay();
	
};

