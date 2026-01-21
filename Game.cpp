#include "Game.h"
#include "funcs.h"

constexpr sf::Color bgColor = { 123,50,230 };


Game::Game(sf::RenderWindow& window, int mapID) : window(window), map(mapID), player(map,arena), ghost1(map,arena), ghost2(map,arena) {


    grid_lines = drawGrid(window, grid_size);

    arena.setSize({ grid_size * board_cell_width, grid_size * board_cell_height });

    arena.setOrigin(arena.getGeometricCenter());
    arena.setPosition({ width / 2.f, height / 2.f });
    arena.setFillColor(sf::Color::Black);

    
}


void Game::inputSystem() {



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
        //if(player.shape.getGlobalBounds().findIntersection(.getGlobalBounds())
        arena.getGlobalBounds();
        player.shape.getGlobalBounds();

        player.move(Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
        player.move(Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
        player.move(Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
        player.move(Right);
    }
}

void portals(Player& player, float width, float height, float grid_size) {

    float posX = player.shape.getPosition().x;
    float posY = player.shape.getPosition().y;

    float buffer = 50.f;

    if (posX < -buffer) {
        player.shape.setPosition({ width + grid_size / 2.f,posY });
    }
    else if (posX > width + buffer) {
        player.shape.setPosition({ 0 - grid_size / 2.f,posY });
    }
    else if (posY < -buffer) {
        player.shape.setPosition({ posX, height + grid_size / 2.f });
    }
    else if (posY > height + buffer) {
        player.shape.setPosition({ posX, 0 - grid_size / 2.f });
    }
}

void Game::update() {
	portals(player, width, height, grid_size);

	//INPUTS
	inputSystem();
    //GHOST MOVEMENT
}

void Game::render() {
    window.clear(bgColor);

    window.draw(arena);

    window.draw(player.shape);
    window.draw(ghost1.shape);
    window.draw(ghost2.shape);

    window.draw(grid_lines);

    update();

    window.display();

}