#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Engine::Engine()
    : window(
        sf::VideoMode{ sf::Vector2u{
            static_cast<unsigned>(width),
            static_cast<unsigned>(height)
        } },
        "Pacman by Hidomen",
        sf::Style::Default
    ),mapID(1), mainMenu(window, state, width), game(window, mapID), pause(window)
{
    //mapID = 1;
    state = MenuState::MainMenu;
    
}

void Engine::handleEvents() {
    //handling events
    while (std::optional event = window.pollEvent()) {

        if (event->is<sf::Event::Closed>()) {
            std::cout << "[ENGINE] - Program is closed. By window." << std::endl;
            state = MenuState::Exit;
        }

        //key pressed states
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

            //escape->>close
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                std::cout << "[ENGINE] - Program is closed. By 'ESC' button." << std::endl;
                state = MenuState::Exit;
            }

            if (keyPressed->scancode == sf::Keyboard::Scancode::Enter && state == MenuState::InGame) { //for a brief moment
                state = MenuState::Pause;
            }

            
        }
    }

}

void Engine::run() {
    while (isOpen()) {

        handleEvents();

        switch (state)
        {
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
    
    
}

bool Engine::isOpen() {
    return window.isOpen();
}