#include "../Header Files/SoundManager.h"

SoundManager::SoundManager() : isEating(false), startDuration(0.f),

	start(start), menuTheme(), intermission(intermission), 
	ghostMove(ghostMove), ghostRetreat(ghostRetreat),
	pacmanMove(pacmanMove), pacmanEat(pacmanEat), pacmanFruit(pacmanFruit), pacmanInvincible(pacmanInvincible)
{
	if (!startBuffer.loadFromFile("./Assets/Sounds/start.wav")) {

	}
	if (!menuTheme.openFromFile("./Assets/Sounds/main-theme.wav")) {

	}
	if (!intermissionBuffer.loadFromFile("./Assets/Sounds/empty.ogg")) {

	}
	if (!ghostMoveBuffer.loadFromFile("./Assets/Sounds/empty.ogg")) {

	}
	if (!ghostRetreatBuffer.loadFromFile("./Assets/Sounds/empty.ogg")) {

	}
	if (!pacmanMoveBuffer.loadFromFile("./Assets/Sounds/empty.ogg")) {

	}
	if (!pacmanEatBuffer.loadFromFile("./Assets/Sounds/pacman-eat-2.ogg")) {

	}
	if (!pacmanFruitBuffer.loadFromFile("./Assets/Sounds/empty.ogg")) {

	}
	if (!pacmanInvincibleBuffer.loadFromFile("./Assets/Sounds/siren.ogg")) {

	}

	start.setBuffer(startBuffer);
	startDuration = startBuffer.getDuration().asSeconds();

	
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
		start.stop();
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

	//std::cout << "OFFSET: " << pacmanEat_playTime.asSeconds() << "DURATION: " << pacmanEat_durationTime.asSeconds() << std::endl;

	if ((pacmanEat_playTime == pacmanEat_durationTime || 0 == pacmanEat_playTime.asSeconds()) && isEating) {

			pacmanEat.play();
	}
}

