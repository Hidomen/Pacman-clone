#include "SoundManager.h"

SoundManager::SoundManager() : 
	start(start), menuTheme(), intermission(intermission), 
	ghostMove(ghostMove), ghostRetreat(ghostRetreat),
	pacmanMove(pacmanMove), pacmanEat(pacmanEat), pacmanFruit(pacmanFruit), pacmanInvincible(pacmanInvincible)
{
	if (!startBuffer.loadFromFile("./Sounds/start.wav")) {

	}
	if (!menuBuffer.loadFromFile("./Sounds/main-theme.wav")) {

	}
	if (!intermissionBuffer.loadFromFile("./Sounds/empty.ogg")) {

	}
	if (!ghostMoveBuffer.loadFromFile("./Sounds/empty.ogg")) {

	}
	if (!ghostRetreatBuffer.loadFromFile("./Sounds/empty.ogg")) {

	}
	if (!pacmanMoveBuffer.loadFromFile("./Sounds/empty.ogg")) {

	}
	if (!pacmanEatBuffer.loadFromFile("./Sounds/pacman-eat-2.ogg")) {

	}
	if (!pacmanFruitBuffer.loadFromFile("./Sounds/empty.ogg")) {

	}
	if (!pacmanInvincibleBuffer.loadFromFile("./Sounds/siren.ogg")) {

	}

	start.setBuffer(startBuffer);

	menuTheme.openFromFile("./Sounds/main-theme.wav");
	menuTheme.setLooping(true);


	intermission.setBuffer(intermissionBuffer);
	ghostMove.setBuffer(ghostMoveBuffer);
	ghostRetreat.setBuffer(ghostRetreatBuffer);
	pacmanMove.setBuffer(pacmanMoveBuffer);
	
	pacmanEat.setBuffer(pacmanEatBuffer);
	//pacmanEat.setLooping(true);

	pacmanFruit.setBuffer(pacmanFruitBuffer);
	pacmanInvincible.setBuffer(pacmanInvincibleBuffer);
}

void SoundManager::stopAll() {
	start.stop();
	menuTheme.stop();
	intermission.stop();
	ghostMove.stop();
	ghostRetreat.stop();
	pacmanMove.stop();
	pacmanEat.stop();
	pacmanFruit.stop();
	pacmanInvincible.stop();
}

void SoundManager::pauseAll() {
	start.pause();
	menuTheme.pause();
	intermission.pause();
	ghostMove.pause();
	ghostRetreat.pause();
	pacmanMove.pause();
	pacmanEat.pause();
	pacmanFruit.pause();
	pacmanInvincible.pause();

}

void SoundManager::statePlay(MenuState state) {
	switch (state){

	case MenuState::MainMenu:
		menuTheme.play();
		break;
	case MenuState::MainOptions:
		break;
	case MenuState::InGame:
		menuTheme.stop();
		start.play();
		break;
	case MenuState::Pause:
		pauseAll();
		break;
	case MenuState::InGameOptions:
		break;
	case MenuState::Exit:
		break;
	}
}

void SoundManager::generalPlay() {
	
	pacmanEat_playTime = pacmanEat.getPlayingOffset();
	pacmanEat_durationTime = pacmanEatBuffer.getDuration();

	std::cout << "OFFSET: " << pacmanEat_playTime.asSeconds() << "DURATION: " << pacmanEat_durationTime.asSeconds() << std::endl;


	if (pacmanEat_playTime == pacmanEat_durationTime || pacmanEat_playTime.asSeconds() == 0) {
		pacmanEat.stop();

	}
	else {
		return;
	}

	if (eating) {
		pacmanEat.play();
	}
}

void SoundManager::eatState(bool isEat) {
	if (isEat) {
		eating = true;
	}
	else {
		eating = false;
	}
}

