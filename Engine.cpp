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
    state = sMainMenu;
    
}

void Engine::handleEvents() {
    //handling events
    while (std::optional event = window.pollEvent()) {

        if (event->is<sf::Event::Closed>()) {
            std::cout << "[ENGINE] - Program is closed. By window." << std::endl;
            window.close();
        }

        //key pressed states
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

            //escape->>close
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                std::cout << "[ENGINE] - Program is closed. By 'ESC' button." << std::endl;
                window.close();
            }

            if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) { //for a brief moment
                state = static_cast<MenuState>((state + 1) % 5);
            }

            
        }
    }

}

void Engine::run() {
    while (isOpen()) {

        handleEvents();

        switch (state)
        {
        case sMainMenu:
            mainMenu.update();
            mainMenu.render();
            break;
        case sMainOptions:
            break;
        case sInGame:
            game.update();
            game.render();
            break;
        
        case sPause:
            break;
        case sInGameOptions:
            break;
        }

        
    }
    
    
}

bool Engine::isOpen() {
    return window.isOpen();
}