#include "StateManager.h"

//mapID(1),
StateManager::StateManager(sf::RenderWindow& window) : window(window),  mainMenu(window, initState, width), game(window, 1), pause(window) {
	contState = MenuState::MainMenu;
}

//doesn't change anything in states, just contionus where they left. Use for pause and resume,
void StateManager::changeContState(MenuState newState) {
    contState = newState;
    initState = contState;

    switch (contState) {//just printing on terminal

    case MenuState::MainMenu:
        std::cout << "CONT STATE CHANGED: MAIN MENU" << std::endl;
        break;

    case MenuState::MainOptions:
        std::cout << "CONT STATE CHANGED: MAIN OPTIONS" << std::endl;
        break;

    case MenuState::InGame:
        std::cout << "CONT STATE CHANGED: IN-GAME" << std::endl;
        break;

    case MenuState::Pause:
        std::cout << "CONT STATE CHANGED: PAUSE" << std::endl;
        break;

    case MenuState::InGameOptions:
        std::cout << "CONT STATE CHANGED: IN-GAME OPTIONS" << std::endl;
        break;

    case MenuState::Exit:
        std::cout << "CONT STATE CHANGED: EXIT" << std::endl;
        break;
    }
}

//activates initilization of states. Use for restart, 
void StateManager::changeInitState(MenuState newState) {
	contState = newState;
    initState = contState;

    switch (contState) {

    case MenuState::MainMenu:
        std::cout << "INIT STATE CHANGED: MAIN MENU" << std::endl;
        break;

    case MenuState::MainOptions:
        std::cout << "INIT STATE CHANGED: MAIN OPTIONS" << std::endl;
        break;

    case MenuState::InGame:
        std::cout << "INIT STATE CHANGED: IN-GAME" << std::endl;
        game.init();
        break;

    case MenuState::Pause:
        std::cout << "INIT STATE CHANGED: PAUSE" << std::endl;
        break;

    case MenuState::InGameOptions:
        std::cout << "INIT STATE CHANGED: IN-GAME OPTIONS" << std::endl;
        break;

    case MenuState::Exit:
        std::cout << "INIT STATE CHANGED: EXIT" << std::endl;
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
