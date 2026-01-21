#include "Game.h"
#include "funcs.h"

constexpr sf::Color bgColor = { 123,50,230 };


Game::Game(sf::RenderWindow& window, int mapID) : window(window), map(mapID, border), player(map), ghost1(map), ghost2(map) {


    grid_lines = drawGrid(window, tileSize);

    arena.setSize({ tileSize * (board_cell_width), tileSize * (board_cell_height) });

    arena.setPosition({ width / 2.f, height / 2.f });
    arena.setOrigin(arena.getGeometricCenter());

    arena.setFillColor(sf::Color::Black);


    border.up_pos    = arena.getGlobalBounds().getCenter().y - arena.getSize().y / 2.f;
    border.down_pos  = arena.getGlobalBounds().getCenter().y + arena.getSize().y / 2.f;
    border.right_pos = arena.getGlobalBounds().getCenter().x + arena.getSize().x / 2.f;
    border.left_pos  = arena.getGlobalBounds().getCenter().x - arena.getSize().x / 2.f;

    map.printMap();

    delayTime = .20f;

}


void Game::inputSystem(float currentTime) {


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {

        player.changeDirection(Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {

        player.changeDirection(Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {

        player.changeDirection(Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {

        player.changeDirection(Right);
    }
    
    if (delayTime > currentTime) return;

    player.move();
    clock.restart();

}


void Game::update() {
    float time = clock.getElapsedTime().asSeconds();
    //std::cout << "CLOCK: " << time << std::endl;
	
    //INPUTS
	inputSystem(time);
    //GHOST MOVEMENT
}

void Game::render() {
    window.clear(bgColor);

    window.draw(arena);

    window.draw(player.shape);
    window.draw(ghost1.shape);
    window.draw(ghost2.shape);

    

    update();

    for (auto& tile : map.tiles) {
        window.draw(tile);
    }

    window.draw(grid_lines);

    window.display();

    
}