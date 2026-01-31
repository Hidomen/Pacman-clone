#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Engine::Engine()
    : window(
        sf::VideoMode{ sf::Vector2u{
            static_cast<unsigned>(width),
            static_cast<unsigned>(height)
        } },
        "Pacman by Hidomen", sf::Style::Default
    ), stateManager(window)
{
    //mapID = 1;
}

void Engine::handleEvents() {
    //handling events
    while (std::optional event = window.pollEvent()) {

        if (event->is<sf::Event::Closed>()) {
            std::cout << "[▬] - Program is closed. By window." << std::endl;
            stateManager.changeInitState(MenuState::Exit);
        }

        //key pressed states
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

            //escape->>goto MainMenu->>Close
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                if (stateManager.contState != MenuState::MainMenu) {
                    stateManager.changeInitState(MenuState::MainMenu);
                }
                else {
                    std::cout << "[] - Program is closed. By 'ESC' button." << std::endl;
                    stateManager.changeInitState(MenuState::Exit);
                }
                
            }

            //Enter->>Pause or UnPause the Game
            if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {

                if (stateManager.contState == MenuState::InGame) {
                    
                    stateManager.changeContState(MenuState::Pause);
                }
                else if (stateManager.contState == MenuState::Pause) {

                    stateManager.changeContState(MenuState::InGame);
                }
            }
        } 
        //
    }
}

void Engine::run() {
    while (window.isOpen()) {

        handleEvents();

        stateManager.update();
    }
}