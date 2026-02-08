#include "StateManager.h"

//mapID(1),
StateManager::StateManager(sf::RenderWindow& window, sf::Font& font) : window(window), font(font), 
mainMenu(window, initState, font), 
game(window, soundManager, font, 1), 
pause(window, font) {

    changeInitState(MenuState::MainMenu);
}

//doesn't change anything in states, just contionus where they left. Use for pause and resume,
void StateManager::changeContState(MenuState newState) {
    contState = newState;
    initState = contState;

    soundManager.statePlay(contState);


    switch (contState) {//just printing on terminal

    case MenuState::MainMenu:
        std::cout << "[STATE-MANAGER]_CONT : MAIN MENU" << std::endl;
        break;

    case MenuState::MainOptions:
        std::cout << "[STATE-MANAGER]_CONT : MAIN OPTIONS" << std::endl;
        break;

    case MenuState::InGame:
        std::cout << "[STATE-MANAGER]_CONT : IN-GAME" << std::endl;
        break;

    case MenuState::Pause:
        std::cout << "[STATE-MANAGER]_CONT : PAUSE" << std::endl;
        break;

    case MenuState::InGameOptions:
        std::cout << "[STATE-MANAGER]_CONT : IN-GAME OPTIONS" << std::endl;
        break;

    case MenuState::Exit:
        std::cout << "[STATE-MANAGER]_CONT : EXIT" << std::endl;
        break;
    }
}

//activates initilization of states. Use for restart, 
void StateManager::changeInitState(MenuState newState) {
	contState = newState;
    initState = contState;

    soundManager.statePlay(initState);

    switch (initState) {

    case MenuState::MainMenu:
        std::cout << "[STATE-MANAGER]_INIT : MAIN MENU" << std::endl;
        break;

    case MenuState::MainOptions:
        std::cout << "[STATE-MANAGER]_INIT : MAIN OPTIONS" << std::endl;
        break;

    case MenuState::InGame:
        std::cout << "[STATE-MANAGER]_INIT : IN-GAME" << std::endl;
        //game = Game(window, soundManager, 1);
        game.init();
        break;

    case MenuState::Pause:
        std::cout << "[STATE-MANAGER]_INIT : PAUSE" << std::endl;
        break;

    case MenuState::InGameOptions:
        std::cout << "[STATE-MANAGER]_INIT : IN-GAME OPTIONS" << std::endl;
        break;

    case MenuState::Exit:
        std::cout << "[STATE-MANAGER]_INIT : EXIT" << std::endl;
        break;
    }
}

void StateManager::update() {

    if (initState != contState) {

        changeInitState(initState);
    }

    switch (contState) {

    case MenuState::MainMenu:

        mainMenu.update();
        mainMenu.render();
        break;

    case MenuState::MainOptions:

        break;

    case MenuState::InGame:

        game.update();
        game.render();
        break;

    case MenuState::Pause:

        pause.update();
        pause.render();
        break;

    case MenuState::InGameOptions:

        break;

    case MenuState::Exit:

        window.close();
        break;
    }
}
