#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Engine::Engine()
    : window(
        sf::VideoMode{ sf::Vector2u{
            static_cast<unsigned>(width),
            static_cast<unsigned>(height)
        } },
        "MY TITLE",
        sf::Style::Default
    ), game(window,5) //bunu nas?l yapt?m unttum mk
{
    
    //mapID = 1;
    


    
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

            
        }
    }

}


void Engine::run() {
    while (isOpen()) {
        handleEvents();
        game.update();
        game.render();
    }
    
    
}

bool Engine::isOpen() {
    return window.isOpen();
}